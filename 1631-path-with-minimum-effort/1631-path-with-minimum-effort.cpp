class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        set<tuple<int, int, int>> st;
        st.insert({0, 0, 0});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!st.empty()) {
            auto [effort, r, c] = *st.begin();
            st.erase(st.begin());

            if (r == n - 1 && c == m - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {
                int drow = r + dr[i];
                int dcol = c + dc[i];

                if (drow < 0 || drow >= n || dcol < 0 || dcol >= m) {
                    continue;
                }

                int diff = abs(heights[r][c] - heights[drow][dcol]);
                int neweffort = max(effort, diff);
                if (neweffort < dist[drow][dcol]) {
                    st.erase({dist[drow][dcol], drow, dcol});
                    dist[drow][dcol] = neweffort;
                    st.insert({neweffort, drow, dcol});
                }
            }
        }
        return 0;
    }
};