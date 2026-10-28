
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int X = 1024;
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(X, false)
            )
        );
        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i > 0) {
                    for (int x = 0; x < X; x++) {
                        if (dp[i - 1][j][x]) {
                            int newXor = x ^ grid[i][j];
                            dp[i][j][newXor] = true;
                        }
                    }
                }
                if (j > 0) {
                    for (int x = 0; x < X; x++) {
                        if (dp[i][j - 1][x]) {
                            int newXor = x ^ grid[i][j];
                            dp[i][j][newXor] = true;
                        }
                    }
                }
            }
        }
        for (int x = 0; x < X; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }
        return -1;
    }
};
