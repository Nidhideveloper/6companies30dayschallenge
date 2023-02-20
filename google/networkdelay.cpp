class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int> > > graph(n+1);
        for (auto e : times) {
            int fr_node = e[0];
            int to_node = e[1];
            int cost = e[2];
            graph[fr_node].push_back(make_pair(cost, to_node));            
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push(make_pair(0, k));        
        while (!pq.empty()) {
            pair<int,int> pp = pq.top();
            pq.pop();
            for (auto neighbor : graph[pp.second]) {
                int temp = dist[pp.second] + neighbor.first;
                if (temp < dist[neighbor.second]) {
                    dist[neighbor.second] = temp;
                    pq.push(make_pair(temp, neighbor.second));
                }
            }            
        }        
        int mx = INT_MIN;
        for (int i = 1; i < dist.size(); ++i) {
            mx=max(mx, dist[i]);
        }
        
        return mx == INT_MAX? -1 : mx;
    }
};