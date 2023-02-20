class Solution {
public:
    int countDistinct(vector<int>& nums, int mx, int p) {
        int n=nums.size();
    int ans=0;
    //k represents the window size
    
    for(int k=1;k<=n;k++){
        int cnt=0;
        //cnt represent the count of values divisible by p 
        
        set<vector<int>>s; //set of vector used to get distinct subarray
        
        vector<int>tt;//store the subarray
        
        for(int i=0;i<n;i++){
            //Sliding window Approach

            if(i<k){
                tt.push_back(nums[i]);
                if(nums[i]%p==0){
                    cnt++;
                }
                continue; 
            }
            if(cnt<=mx){     //Base condition for valid Sliding Window
                s.insert(tt);
            }
            if(tt[0]%p==0) cnt--;    //Removed from Sliding window 
            tt.erase(tt.begin());
            
            if(nums[i]%p==0) cnt++;   //Included in Sliding window
            tt.push_back(nums[i]);
        }
        if(cnt<=mx){             //for including last sliding window
                s.insert(tt);
        }
        
        ans+=s.size();  //Adding up the answer
    }
    return ans;
    }
};