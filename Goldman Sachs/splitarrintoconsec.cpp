class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto i:nums) mpp[i]++;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]]==0) continue;
            if(mp[nums[i]-1]>0){
                mpp[nums[i]]--;
                mp[nums[i]-1]--;
                mp[nums[i]]++;
            }
            else if(mpp[nums[i]+1]>0 && mpp[nums[i]+2]>0)
            {   mpp[nums[i]]--;
                mpp[nums[i]+1]--;
                mpp[nums[i]+2]--;
                mp[nums[i]+2]++;
              
            }else
                return false;
        }
        return true;
    }
};