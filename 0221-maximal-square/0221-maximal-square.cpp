class Solution {
public:
    int maxside= 0;
    int solve(int row ,int col,vector<vector<int>>& dp,vector<vector<char>>& matrix){
        int m = matrix.size();
        int n= matrix[0].size();
        if (row >= m || col >= n) {
            return 0;
        }

        if (matrix[row][col] == '0') {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int down = solve(row+1, col,dp, matrix);
        int right = solve(row, col+1,dp, matrix);
        int diagonal = solve(row+1, col+1,dp, matrix);
        dp[row][col]= 1+ min({down , right , diagonal});
        maxside= max(maxside, dp[row][col]);
    
        return dp[row][col];

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
      for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
        solve(row, col, dp, matrix);
    }
}
        return maxside * maxside;
    }
};