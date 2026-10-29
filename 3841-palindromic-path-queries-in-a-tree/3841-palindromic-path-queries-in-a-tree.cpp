class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, tin, tout;
    vector<int> parentMask;
    string s;
    int timer = 0, LOG;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            if (r + 1 <= n)
                update(r + 1, val);
        }
    };

    unique_ptr<Fenwick> bit;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            parentMask[v] =
                parentMask[u] ^ (1 << (s[v] - 'a'));

            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->s = s;
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        parentMask.assign(n, 0);

    
        parentMask[0] = 1 << (s[0] - 'a');
        dfs(0, 0);

        bit = make_unique<Fenwick>(n);

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c - 'a'));

                if (delta != 0) {
                    bit->rangeUpdate(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                ss >> v;

                int maskU = parentMask[u] ^ bit->query(tin[u]);
                int maskV = parentMask[v] ^ bit->query(tin[v]);

                int w = lca(u, v);

                int pathMask = maskU ^ maskV ^
                               (1 << (s[w] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};