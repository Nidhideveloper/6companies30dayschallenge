class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
            
            vector<int> adj[n];
			for(int i=0;i<prerequisites.size();i++) 
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
			vector<int> tmp;
			vector<int> in(n,0);
			queue<int>q;
			for(int i=0;i<n;i++){
				for(auto j:adj[i]) in[j]++;
			}
			for(int i=0;i<n;i++){
				if(!in[i]) q.push(i);
			}
			while(!q.empty()){
				int node=q.front();
				q.pop();
				tmp.push_back(node);
				for(auto i:adj[node]){
					in[i]--;
					if(!in[i]) q.push(i);
				}
			}
			return tmp.size()==n;
    }
};