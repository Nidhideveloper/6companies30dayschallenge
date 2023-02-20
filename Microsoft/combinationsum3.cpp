class Solution {
public:
    void f(vector<vector<int>> &ans, vector<int> &temp, int cur, int k, int n){
        if(n<0 || temp.size()>k) return;
        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=cur; i<=9;i++){
            temp.push_back(i);
            f(ans, temp, i+1, k, n-i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans, temp, 1, k, n);
        return ans;
    }
};