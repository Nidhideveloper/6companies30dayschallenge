class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int temp=0;
        for(auto it:numsDivide){
            temp=__gcd(temp, it);
            
        }
        int cnt=0;
        int sz=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==temp || temp%nums[i]==0) break;
            else{
                cnt++, sz--;
            }
        }
        if(sz==0) return -1;
        return cnt;
       
    }
};