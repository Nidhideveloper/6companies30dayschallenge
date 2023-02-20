
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        //we need to find the min number in the matrix and also count of negative numbers in the matrix
        int mn=INT_MAX,cnt=0;
        long long int sum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=matrix[i][j];
                mn=min(mn,abs(val));
                if(val<0)
                    cnt++;
                sum+=abs(val);
            }
        }
        if(cnt%2==0)
            return sum;
        else
            return sum-2*mn;
    }
};