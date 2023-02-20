class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int s=0;
        int f=0;
        for(int i=0; i<nums.size(); i++){
            s+=nums[i];
            f+=i*nums[i];
        }
        int total=f;
        for(int i=nums.size()-1; i>=0; i--){
            f=f+s-nums[i]*nums.size();
            total=max(total, f);
        }
        return total;
    }
};