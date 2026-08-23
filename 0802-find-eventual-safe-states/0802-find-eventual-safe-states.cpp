class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revgraph(n);
        vector<int>outorder(n,0);
        for(int i=0;i<n;i++){
            outorder[i]=graph[i].size();
            for(auto node:graph[i]){
                revgraph[node].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outorder[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto neigh : revgraph[node]){
                outorder[neigh]--;
                if(outorder[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};