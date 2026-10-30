class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist( n, vector<long long>(k + 1, LLONG_MAX));

        using State = tuple<long long, int, int>;

        priority_queue< State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();

            if (d != dist[u][run]) {
                continue;
            }

            if (u == n - 1) {
                return static_cast<int>(d);
            }

            for (auto [v, w] : adj[u]) {
                int newRun;

                if (labels[u] == labels[v]) {
                    newRun = run + 1;
                } else {
                    newRun = 1;
                }

                if (newRun > k) {
                    continue;
                }

                long long newDist = d + w;

                if (newDist < dist[v][newRun]) {
                    dist[v][newRun] = newDist;
                    pq.push({newDist, v, newRun});
                }
            }
        }

        return -1;
    }
};