class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == tmp[i]) {
            i++;
        }
        while (j > i && nums[j] == tmp[j]) {
            j--;
        }
        return j + 1 - i;
    }
};