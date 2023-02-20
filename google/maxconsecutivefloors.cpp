class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = max(a[0] - bottom, top - a[n - 1]);
        for (int i = 1; i < n; ++i)
            ans = max(ans, a[i] - a[i - 1] - 1);
        return ans;
    }
};