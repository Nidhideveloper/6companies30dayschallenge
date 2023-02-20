class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        int ans = 0;
        vector<int> v;
        int n=s.size();
        for(int i=0;i<n;i++) v.push_back(i);
        do{
            int curr = 0;
            for(int i = 0;i<n; i++)
                for(int j=0;j<s[v[i]].size();j++)
                    curr += (s[v[i]][j] == m[i][j]);
            ans = max(ans, curr);
        } while(next_permutation(v.begin(), v.end()) );
        return ans;
    }
};