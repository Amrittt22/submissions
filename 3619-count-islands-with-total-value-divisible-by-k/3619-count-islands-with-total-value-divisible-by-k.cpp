class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                long long sum=0;
                stack<pair<int,int>>st;
                st.push({i,j});
                sum+=grid[i][j];
                grid[i][j]=0;
                while(!st.empty()){
                    auto [row,col]=st.top();
                    st.pop();

                    for(int d=0;d<4;d++){
                        int nr=row+dr[d];
                        int nc=col+dc[d];

                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0){
                            sum+=grid[nr][nc];
                            grid[nr][nc]=0;
                            st.push({nr,nc});
                        }
                    }
                }
                if(sum%k==0)ans++;
            }
        }
        return ans;
    }
};