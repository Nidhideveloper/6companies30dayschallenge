class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int i=0,j=0,ans=0;
        while(j<fruits.size())
        {
            mpp[fruits[j]]++;
            while(mpp.size()>2)
            {
                if(mpp[fruits[i]]==1)
                {
                    mpp.erase(fruits[i]);
                }
                else
                {
                    mpp[fruits[i]]--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};