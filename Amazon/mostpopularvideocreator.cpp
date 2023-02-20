class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long> total;
        unordered_map<string,vector<pair<long,string>>> video;
        long mx = 0;
        int n=creators.size();
        for (int i = 0; i < n; ++i)
        {
            total[creators[i]] += views[i]; 
            mx = max(mx, total[creators[i]]);
            video[creators[i]].emplace_back(-views[i], ids[i]);
        }
        vector<vector<string>> result;
        for (auto&[c,vv] : video)
        {
            if (total[c] != mx) continue;
            result.push_back({c, min_element(vv.begin(),vv.end())->second});
        }
        return result;
    }
};