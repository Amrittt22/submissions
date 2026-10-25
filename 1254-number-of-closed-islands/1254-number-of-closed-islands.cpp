class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int dr[], int dc[]) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        for (int k = 0; k < 4; k++) {
            int nrow = row + dr[k];
            int ncol = col + dc[k];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 0) {

                dfs(nrow, ncol, grid, vis, dr, dc);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j : {0, m - 1}) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs(i, j, grid, vis, dr, dc);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i : {0, n - 1}) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs(i, j, grid, vis, dr, dc);
                }
            }
        }

        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    count++;
                    dfs(i, j, grid, vis, dr, dc);
                }
            }
        }

        return count;
    }
};