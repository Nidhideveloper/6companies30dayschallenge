class Solution {
public:
    vector<vector<int>>adj;
    vector<int>dis;
    int node;
    int dfs(int u,int par,int depth,vector<int>&amount){
        int res = 0;
        if(u==node) dis[u] = 0;
        else dis[u] = amount.size();
        int mx = INT_MIN;
        for(int v:adj[u]){
            if(v==par)continue;
            mx = max(mx,dfs(v,u,depth+1,amount));
            dis[u] = min(dis[u],dis[v]+1);
        }
        if(dis[u]>depth)res+=amount[u];
        else if(dis[u]==depth)res+=amount[u]/2;
        if(mx==INT_MIN) return res;
        else return res+mx;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        node = bob;
        adj.resize(n,vector<int>());
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dis.resize(n);
        return dfs(0,0,0,amount);
    }
    
};