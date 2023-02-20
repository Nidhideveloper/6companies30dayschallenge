class Solution {
public:
const unsigned int M=1000000007;
    int rev(int n) {
    int res = 0;
    for (; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> mpp;
    int res = 0;
    for (auto n : nums)
        res = (res + mpp[n - rev(n)]++) % (M);
    return res;
}
};