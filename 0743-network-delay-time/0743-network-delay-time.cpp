class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()){
            int time  = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto [neigh,wt] : adj[node]){
                if(dist[neigh] > time + wt){
                    dist[neigh] = time + wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int maxTime = *max_element(dist.begin()+1,dist.end());
        if(maxTime == INT_MAX) return -1;
        return maxTime;
    }
};