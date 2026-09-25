class Solution {
public:
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int parent) {
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (tin[v] != -1) {
                // Back edge
                low[u] = min(low[u], tin[v]);
            }
            else {
                // Tree edge
                dfs(v, u);

                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > tin[u]) {
                    ans.push_back({u, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections
    ) {
        adj.resize(n);
        tin.assign(n, -1);
        low.resize(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }
};