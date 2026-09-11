class DisjointSet{
    public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbySize(int u , int v){
        int utp_u=findUpar(u);
        int utp_v=findUpar(v);
        if(utp_u == utp_v) return ;
        if(size[utp_u] < size[utp_v]){
            parent[utp_u]=parent[utp_v];
            size[utp_v]+=size[utp_u];
        }
        else{
            parent[utp_v]=parent[utp_u];
            size[utp_u]+=size[utp_v];
        }
}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
         DisjointSet ds(n);
        int countExtras=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u) == ds.findUpar(v)){
                countExtras++;
            }
            else{
                ds.unionbySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntC++;
        }
        int ans = cntC-1;
        if(countExtras>=ans) return ans;
        return -1;
    }
};