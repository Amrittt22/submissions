class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(abs(target)>totalsum) return 0;
        if((totalsum-target)%2!=0) return 0;
        int sum=(totalsum-target)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int s=0;s<=sum;s++){
                dp[i][s]=dp[i-1][s];
                if(s>=nums[i-1]){
                    dp[i][s]+=dp[i-1][s-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};