class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9+7;
        vector<long long>dist(n,1e18);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long , int>>> pq;
        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d>dist[u]) continue;

            for(auto [v ,wt] : adj[u]){
                long long newDist = d + wt;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist,v});
                }
                else if(newDist == dist[v]){
                        ways[v]=(ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1];
    }
};