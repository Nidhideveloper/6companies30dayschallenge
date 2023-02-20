class Solution {
public:
    long long int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end,int d)
    {

        
        int l = start, r = mid + 1;
        while(l <= mid && r <= end)
        {
            if(nums[l]<=(nums[r]+d))  // if (nums[l]<=nums[r]+d) then all values from nums[r] to nums[end] will be be having their summation with d greater than or equal to nums[l]
            {
                count += (end - r+1);
                l++;
            }
            else      // otherwise we need to increment r so that we can find match for nums[l]
            {
                r++;
            }
        }
         // sort all values from start to end
        sort(nums.begin() + start, nums.begin() + end + 1);  // (Sort using two-pointers for better time complexity)
        return;
         
    }
    void mergesort(vector<int>& arr, int l, int r,int d)
    {
        if(l >= r) 
            return;
        
        int m = l+(r-l)/2;
        mergesort(arr,l, m,d);
        mergesort(arr,m+1,r,d);
        checkCount(arr,l,m,r,d);
        return;
        
    }
    long long numberOfPairs(vector<int>& arr, vector<int>& brr, int d) 
    {
        count = 0;
        int n = arr.size();
        vector<int> c(n);  
        
        for(int i=0;i<n;i++)
            c[i]=arr[i]-brr[i];               

        mergesort(c,0,n-1,d);
		
        return count;
    }
};