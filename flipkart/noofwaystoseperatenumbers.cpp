class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        int a[n][n], b[n][n];
        int mod = 1000000007;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = n-1; i >= 0; i--)
        {
            if(num[i]=='0')continue;
            for(int j = n-1, sum = 0; j >= i; j--)
            {
                if(j==n-1) a[i][j] = 1;
                else
                {
                    int len = j-i+1, first = j+1, last = first + len, cnt = 0;
                    if(last<=n && memcmp(&num[i],&num[first],len) <= 0) cnt = (cnt+a[first][last-1])%mod;
                    if(last< n)cnt = (cnt+b[first][last])%mod;
                    a[i][j] = cnt;
                }
                b[i][j] = sum = (sum+a[i][j])%mod;
            }
        }
        return b[0][0];
    }
};