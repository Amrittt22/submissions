
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += stones[i];
        }

        int target = totalSum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                dp[i][t] = dp[i - 1][t];

                if (stones[i - 1] <= t) {
                    dp[i][t] = dp[i][t] || dp[i - 1][t - stones[i - 1]];
                }
            }
        }

        for (int s = target; s >= 0; s--) {
            if (dp[n][s]) {
                return totalSum - 2 * s;
            }
        }

        return 0;
    }
};
