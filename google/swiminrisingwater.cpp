class Solution {
public:
    //int swimInWater(vector<vector<int>>& grid) {
        /*priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size(), m = grid[0].size();
        int dirx[4] = {1, -1, 0, 0};
        int diry[4] = {0, 0, -1, 1};
        int val = 0;
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        while(!pq.empty())
        {
            int sz = pq.size();
            while(sz--)
            {
                pair<int, pair<int, int>> tp = pq.top();
                int x = tp.second.first, y = tp.second.second;
                pq.pop();
                val = max(val, tp.first);
                if(x == n-1 && y == m-1) return val;
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) continue;
                    if(grid[nxtx][nxty] == -1) continue;
                    pq.push({grid[nxtx][nxty],{nxtx, nxty}});
                    grid[nxtx][nxty] = -1;
                }
            }
        }
        return val;*/

        int n, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int swimInWater(vector<vector<int>>& grid) {
    n = size(grid);        
    vector<vector<int>>vis(n, vector<int>(n));
	int minReq = max({ 2*(n-1), grid[0][0], grid[n-1][n-1] });
    for(int w_lvl = minReq; w_lvl < n*n; w_lvl++) {
        if(dfs(grid, vis, 0, 0, w_lvl)) return w_lvl;
        for_each(begin(vis), end(vis), [](auto& v){fill(begin(v), end(v), 0);});  // reset the vis array back to not-visited
    }        
    return n*n;
}

bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int w_lvl) {
    if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] > w_lvl) return false; // out-of-bound / already visited / cell value > max w_lvl allowed
    if(i == n - 1 && j == n - 1) return true;
    vis[i][j] = true;
    for(int k = 0; k < 4; k++) // search all available option till any of it leads us to the end
        if(dfs(grid, vis, i + moves[k][0], j + moves[k][1], w_lvl)) return true;
    return false;
}
    //}
};