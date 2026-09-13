class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionbySize(int u, int v) {
        int utp_u = findUpar(u);
        int utp_v = findUpar(v);
        if (utp_u == utp_v)
            return;
        if (size[utp_u] < size[utp_v]) {
            parent[utp_u] = parent[utp_v];
            size[utp_v] += size[utp_u];
        } else {
            parent[utp_v] = parent[utp_u];
            size[utp_u] += size[utp_v];
        }
    }
};
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            int n = stones.size();
            DisjointSet dsu(n);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (stones[i][0] == stones[j][0] ||
                        stones[i][1] == stones[j][1]) {
                        dsu.unionbySize(i, j);
                    }
                }
            }
            int components = 0;
            for (int i = 0;i < n; i++) {
                if (dsu.findUpar(i) == i) {
                    components++;
                }
            }
            return n - components;
        }
    };