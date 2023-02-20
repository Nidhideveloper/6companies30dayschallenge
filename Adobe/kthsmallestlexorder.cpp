class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        for(--k; k > 0; )
        {            
            int c = 0;
            for (long long f = static_cast<long long>(ans), l = f + 1;
                f <= n; 
                f *= 10, l *= 10) 
            {
                c += static_cast<int>((min(n + 1LL, l) - f)); 
            }
            
            if (k >= c)
            {   
                ++ans;
                k -= c;
            }
            else
            {   
                ans *= 10;
                --k;
            }
        }
        return ans; 
    }
};