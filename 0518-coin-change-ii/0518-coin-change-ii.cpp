
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        const long long LIMIT = INT_MAX;

        vector<vector<long long>> dp(
            n, vector<long long>(amount + 1, 0)
        );

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                long long notTake = dp[i - 1][j];
                long long take = 0;

                if (coins[i] <= j) {
                    take = dp[i][j - coins[i]];
                }

                dp[i][j] = min(LIMIT, notTake + take);
            }
        }

        return static_cast<int>(dp[n - 1][amount]);
    }
};
