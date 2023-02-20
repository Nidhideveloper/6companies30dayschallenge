class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int i : w){
            if(s.empty())
                s.push_back(i);
            else
                s.push_back(i + s.back());
        }
    }
    
    int pickIndex() {
        int a = s.back();
        int i = rand() % a;
        auto it = upper_bound(s.begin(), s.end(),i);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */