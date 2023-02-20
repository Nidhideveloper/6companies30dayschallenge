class Solution {
public:
    int n;
    int f(int cur,vector<vector<int>>&statements,int mask){
        if(cur==n){
            for(int i=0;i<n;i++){
                if((mask&(1<<i))){
                    for(int j=0;j<n;j++){
                        int val = (mask&(1<<j))?1:0;
                        if(statements[i][j]!=2 && statements[i][j]!=val){
                            return INT_MIN;
                        }
                    }
                }
            }
            return 0;
        }
        int a = f(cur+1,statements,mask);
        int b = 1+f(cur+1,statements,(mask|(1<<cur)));
        return max(a,b);
    }
    int maximumGood(vector<vector<int>>& s) {
        n=s.size();
        int ans = f(0,s,0);
        return ans<0?0:ans;
    }
};