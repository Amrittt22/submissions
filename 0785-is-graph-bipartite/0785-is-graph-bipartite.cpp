class Solution {
public:
    bool dfs(vector<vector<int>>&adj, int node , int col , vector<int>& color){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(adj,it,!col,color)==false) return false;
            }
            else if(color[it]==col)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
               if(dfs(graph,i,0,color)==false) return false;
            }
        
        }
        return true;
    }
};