class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;

        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = INF;

                for (int d : divisors[len]) {
                    int changes = 0;
                    int group_len = len / d;

                    for (int start = 0; start < d; ++start) {
                        int left = i + start;
                        int right = i + start + (group_len - 1) * d;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_changes = min(min_changes, changes);
                }
                cost[i][j] = min_changes;
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        for (int i = 2; i <= n; ++i) {
            dp[1][i] = cost[0][i - 1];
        }

        for (int p = 2; p <= k; ++p) {

            for (int i = 2 * p; i <= n; ++i) {

                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (dp[p - 1][m] + cost[m][i - 1] < dp[p][i]) {
                        dp[p][i] = dp[p - 1][m] + cost[m][i - 1];
                    }
                }
            }
        }

        return dp[k][n];
    }
};