class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0) return false;
        int target=totalSum/2;

         vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int t=1;t<=target;t++){
                dp[i][t]=dp[i-1][t];
                if(nums[i-1]<=t){
                    dp[i][t]=dp[i][t]||dp[i-1][t-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};