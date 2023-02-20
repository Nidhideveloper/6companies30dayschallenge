class Solution {
public:
    double new21Game(int n, int k, int mx) {
        if(k == 0 or n >= k + mx) return 1;
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double sum = 1.0;
        double res = 0;
        for(int i=1; i<n+1; i++) {
            dp[i] = sum / double(mx);
            if(i < k)
                sum += dp[i];
            else
                res += dp[i];
            
            if(i-mx >= 0)
                sum -= dp[i-mx];
        }
        return res;
    }
};