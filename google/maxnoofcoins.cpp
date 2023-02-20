class Solution {
public:
    int maxCoins(vector<int>& a) {
        sort(a.begin(), a.end());
        int res = 0, n = a.size();
        for (int i = n / 3; i < n; i += 2)
            res += a[i];
        return res;
    }
};