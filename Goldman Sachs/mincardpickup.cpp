class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        int mn=INT_MAX;
        map<int, int> mpp;
        /*while(j<n){
            if(mpp.find(nums[j])!=mpp.end()){
                mn=min(j-i+1, mn);
                cout<<mn<<" ";
                mpp.clear();
                i++;
            }
            mpp[nums[j]]++;
            j++;
        }*/

        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mn=min(mn, i-mpp[nums[i]]+1);
            }
            mpp[nums[i]]=i;
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};