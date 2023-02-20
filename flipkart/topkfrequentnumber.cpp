class Solution {
public:
    static bool compare(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second == b.second)
        {
            return (a.first < b.first);
        }

        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m;
        for (auto x : words)
        {
            m[x]++;
        }
        vector<pair<string, int>> s;
        for (auto x : m)
        {
            s.push_back({x.first, x.second});
        }
        
      
        sort(s.begin(), s.end(), compare);
  for(auto x: s)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(s[i].first);
        }
        return ans;
    }
};