class Solution {
public:
    map<vector<int>,int> mpp;
    int shoppingOffers(vector<int>& p, vector<vector<int>>& special, vector<int>& needs) 
    {
        int n=p.size(), m=special.size();
        int without=0;
        for(int i=0; i<n; i++) without+=p[i]*needs[i];
        int mn=without;
        if(mpp.find(needs)!=mpp.end()) return mpp[needs];
        for(int i=0; i<m; i++)
        {
            bool flag=1;
            for(int j=0; j<n; j++) 
            {
                if(special[i][j]>needs[j])
                {
                    flag=0; break;
                }
            }
            if(flag)
            {
                vector<int> temp(n);
                for(int j=0; j<n; j++)
                {
                    temp[j]=needs[j]-special[i][j];
                }
                mn=min(mn, special[i][n]+shoppingOffers(p,special,temp));
                
            }
        }
        return mpp[needs]=mn;
    }
};