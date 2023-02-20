class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<long long,long long>> adj[n];
    for(auto i:roads){
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }
    
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    vector<long long> w(n,0),d(n,LONG_MAX);
    pq.push({0,0});
    d[0]=0;
    w[0]=1;
    int mod=1e9+7;
    
    while(!pq.empty()){
        long long dis=pq.top().first;
        long long node=pq.top().second;
        pq.pop();
        
        for(auto i:adj[node]){
            long long adjNode=i.first;
            long long edgeW=i.second;
            
            if(edgeW+dis< d[adjNode]){
                d[adjNode]=edgeW+dis;
                pq.push({edgeW+dis,adjNode});
                w[adjNode]=w[node];
            }
            else if(edgeW+dis==d[adjNode]){
                w[adjNode]=(w[adjNode]+w[node])%mod;
            }
            
        }
    }
    return w[n-1]%mod;
    }
};