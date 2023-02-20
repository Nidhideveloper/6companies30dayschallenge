class Solution {
bool isSafe(string s){
    int n = s.size();
    if(n>=4 || n<=0)return 0;
    if(n>1 && s[0]=='0')return 0;
    if(n && stoi(s)>255)return 0;
    return 1;
}
void solve(string s,vector<string>& ans,string str,int ind,int pt){
    if(pt==3){
        if(isSafe(s.substr(ind))){
            ans.push_back(str+s.substr(ind));
        }
        return;
    }
    for(int i=ind ;i<s.size() ;i++){
        if(isSafe(s.substr(ind, i-ind+1))){
            str.push_back(s[i]);
            str.push_back('.');
            solve(s,ans,str,i+1,pt+1);
            str.pop_back();
        }
    }
}
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        string st = "";
        if(n<4)return ans;
        solve(s,ans,st,0,0);
        return ans;
    }
};