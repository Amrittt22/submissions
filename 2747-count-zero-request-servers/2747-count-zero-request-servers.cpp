class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int q=queries.size();
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>sortedQueries;
        for(int i=0;i<q;i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(),sortedQueries.end());
        vector<int>ans(q);
        vector<int>freq(n+1,0);
        int activeservers=0;
        int left=0;
        int right=0;
        for(auto &[time,ind]:sortedQueries){
            int start=time-x;
            while(right<m && logs[right][1]<=time){
                int server=logs[right][0];
                if(freq[server]==0){
                    activeservers++;
                }
                freq[server]++;
                right++;
            }
            while(left<right && logs[left][1]<start){
                int server=logs[left][0];
                freq[server]--;
                if(freq[server]==0){
                    activeservers--;
                }
                left++;
            }
            ans[ind]=n-activeservers;
        }
        return ans;
    }
};