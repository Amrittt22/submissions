class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX));
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0) dp[0][a]=a/coins[0];
            else dp[0][a]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int notTake = dp[i-1][a];
                int take=INT_MAX;
                if(coins[i]<=a && dp[i][a-coins[i]]!=INT_MAX){
                    take=1+dp[i][a-coins[i]];
                }
                dp[i][a]=min(notTake,take);
            }
        }
        return dp[n-1][amount]==INT_MAX ?-1:dp[n-1][amount];
    }
};