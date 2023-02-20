class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, long long> mpp;
        const long long N=1000000;
        for(vector<int>& x:rectangles){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            mpp[x1*N+y1]++;
            mpp[x1*N+y2]--;
            mpp[x2*N+y1]--;
            mpp[x2*N+y2]++;
        }
        int n_mark=0;
        for(auto it:mpp)
            if(it.second!=0){
                if(abs(it.second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};