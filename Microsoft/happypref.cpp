class Solution {
public:
    string longestPrefix(string s) {
        long long i1 = 0, i2 = 0, mul = 1, len = 0, mod = 1000000007;
        for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
            int a1 = s[i] - 'a', a2 = s[j] - 'a';
            i1 = (i1 * 26 + a1) % mod;
            i2 = (i2 + mul * a2) % mod;
            mul = mul * 26 % mod;
            if (i1 == i2)
                len = i + 1;
        }
        return s.substr(0, len);
    }
};