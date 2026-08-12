class Solution {
public:
    void dfs(int city , vector<vector<int>>& isConnected , vector<int>& visited){
        int n=isConnected.size();
        visited[city]=1;
        for(int i=0;i<n;i++){
            if(isConnected[city][i]==1 && visited[i]==0){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};