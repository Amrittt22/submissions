class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);
        auto dfsFindParents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = lastSeen[c];
            if (u != 0 && prev != -1) {
                newParent[u] = prev;
            }

            lastSeen[c] = u;
            for (int v : origAdj[u]) {
                self(self, v);
            }
            lastSeen[c] = prev;
        };

        dfsFindParents(dfsFindParents, 0);
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        auto dfsSubtreeSize = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : newAdj[u]) {
                sz += self(self, v);
            }
            ans[u] = sz;
            return sz;
        };

        dfsSubtreeSize(dfsSubtreeSize, 0);
        return ans;
    }
};