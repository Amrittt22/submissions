class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto edge:prerequisites){
                int u=edge[0];
                int v=edge[1];

                adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                inorder[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
                if(inorder[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        else return {};
    }
};