class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes, int pos = 0) {
        unordered_map<int, int> mpp;
        set<pair<int, int>> s;
        for (auto n : barcodes) ++mpp[n];
        for (auto it:mpp) s.insert({ it.second, it.first });
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
                if (pos >=barcodes.size()) pos = 1;
                barcodes[pos] = it->second;
            }
        }
        return barcodes;
    }
};