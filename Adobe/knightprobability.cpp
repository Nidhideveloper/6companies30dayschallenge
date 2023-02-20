class Solution {
public:
    double knightProbability(int n, int k, int row, int col) 
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n, vector<double>(n, -1)));
        return solve(n, k, row, col, dp);
    }

    double solve(int n, int k, int row, int col, vector<vector<vector<double>>>& dp)
    {
        if (row < 0 || row >= n || col < 0 || col >= n) return 0;
        if (k == 0) return 1;
        
        if (dp[k][row][col] != -1)
            return dp[k][row][col];
        
        double total = solve(n, k - 1, row - 2, col + 1, dp) + solve(n, k - 1, row - 1, col + 2, dp)
                    + solve(n, k - 1, row + 1, col + 2, dp) + solve(n, k - 1, row + 2, col + 1, dp)
                    + solve(n, k - 1, row + 2, col - 1, dp) + solve(n, k - 1, row + 1, col - 2, dp)
                    + solve(n, k - 1, row - 1, col - 2, dp) + solve(n, k - 1, row - 2, col - 1, dp);
            
        total = total / 8;
        return dp[k][row][col] = total;
    }
};