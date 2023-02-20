class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto [x,y]:dirs){
            int i=r+x;
            int j=c+y;
            
            if(i>=0&&j>=0&&i<=m-1&&j<=n-1&&vis[i][j]!=1&&grid[i][j]!=1){
                dfs(grid,i,j,vis);
                
            }
        }
        return;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         
        vector<vector<int>> vis(m,vector<int>(n,0));
        //traversing the boundary islands
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&vis[i][j]==0&&grid[i][j]==0){
                dfs(grid,i,j,vis);
                
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0&&j>0&&i<m-1&&j<n-1&&vis[i][j]==0&&grid[i][j]==0){
                dfs(grid,i,j,vis);
                ans++;
                }
            }
        }
        return ans;


        
    }
};