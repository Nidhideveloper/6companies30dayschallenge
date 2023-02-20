class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int sz=nums[0].size();
        vector<int> ans;
        for(auto it:queries){
            vector<pair<string, int>> m;
            int k=it[0], trim=it[1];
            for(int i=0; i<n; i++){
                string temp=nums[i].substr(sz-trim);
                m.push_back({temp, i});
            }
            sort(m.begin(), m.end());
            ans.push_back(m[k-1].second);
        }
        return ans;
    }
};