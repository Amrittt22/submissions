class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0))
        );

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] =
                        grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

       
        for (int row = n - 2; row >= 0; row--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int cherries = grid[row][j1];

                    if (j1 != j2)
                        cherries += grid[row][j2];

                    int maxi = 0;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if (nj1 >= 0 && nj1 < m &&
                                nj2 >= 0 && nj2 < m) {
                                maxi = max(
                                    maxi,
                                    dp[row + 1][nj1][nj2]
                                );
                            }
                        }
                    }

                    dp[row][j1][j2] = cherries + maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};