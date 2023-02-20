class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n=p.size();
        vector<pair<int,int>> ans(n);
        for(int i=0;i<n;i++) ans[i]={p[i],c[i]}; 
        int i=0;
        sort(ans.begin(),ans.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});
        priority_queue<int> maxProfit;
        while(k--){
            while(i<n && w>=ans[i].second) maxProfit.push(ans[i++].first);
        
            if(!maxProfit.empty()) w+=maxProfit.top(),maxProfit.pop();
        }
        return w;
    }
};