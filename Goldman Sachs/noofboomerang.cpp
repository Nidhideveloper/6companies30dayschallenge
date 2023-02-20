class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0, n=points.size();
        for(int i=0; i<n; i++){
            unordered_map<long, int> mpp(n);
            for(int j=0; j<n; j++){
                if(j==i) continue;
                int distx=points[i][0]-points[j][0];
                int disty=points[i][1]-points[j][1];
                int total=disty*disty;
                total+=distx*distx;
                mpp[total]++;
            }
            for(auto it:mpp){
                if(it.second>1) ans += it.second * (it.second - 1);
            }
        }
        return ans;
    }
};