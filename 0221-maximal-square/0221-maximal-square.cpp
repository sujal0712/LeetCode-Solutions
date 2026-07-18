class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxSide = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                if (matrix[row][col] == '1') {

                    // First row or first column
                    if (row == 0 || col == 0) {
                        dp[row][col] = 1;
                    } else {
                        int top = dp[row - 1][col];
                        int left = dp[row][col - 1];
                        int diagonal = dp[row - 1][col - 1];

                        dp[row][col] =
                            1 + min({top, left, diagonal});
                    }

                    maxSide = max(maxSide, dp[row][col]);
                }
            }
        }

        return maxSide * maxSide;
    }
};