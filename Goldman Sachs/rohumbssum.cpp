class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<int> s;
        for (int l = 1; l <= min(m, n); l += 2) {
            for (int i = 0; i + l <= n; i ++) {
                for (int j = 0; j + l <= m; j ++) {
                    int d = l / 2;
                    if (d == 0) { s.insert(grid[i][j]); }
                    else {
                        int x = i, y = j + d;
                        long long sum = 0;
                        for (int k = 0; k < d; k ++) sum += grid[x++][y++];
                        for (int k = 0; k < d; k ++) sum += grid[x++][y--];
                        for (int k = 0; k < d; k ++) sum += grid[x--][y--];
                        for (int k = 0; k < d; k ++) sum += grid[x--][y++];
                        s.insert(sum);
                    }
                }
            }
        }
        
        if (s.size() < 3)
            return vector<int>(s.rbegin(), s.rend());
        
        return vector<int>(s.rbegin(), next(s.rbegin(), 3));
    }
};