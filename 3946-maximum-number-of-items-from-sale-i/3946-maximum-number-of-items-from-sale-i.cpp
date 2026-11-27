class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> free(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        vector<array<int, 2>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({items[i][1], free[i] + 1});
        }

        sort(a.rbegin(), a.rend());

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        int i = 0;

        while (i < n) {
            int p = a[i][0];

            vector<int> cur(budget + 1, NEG);

            while (i < n && a[i][0] == p) {
                int gain = a[i][1];

                for (int b = budget; b >= p; b--) {

                    if (dp[b - p] != NEG) {
                        cur[b] = max(cur[b], dp[b - p] + gain);
                    }

                    if (cur[b - p] != NEG) {
                        cur[b] = max(cur[b], cur[b - p] + gain);
                    }

                    if (dp[b - p] != NEG) {
                        dp[b] = max(dp[b], dp[b - p] + gain);
                    }
                }

                i++;
            }

            for (int b = p; b <= budget; b++) {
                if (cur[b] != NEG) {
                    int total = cur[b] + (budget - b) / p;
                    ans = max(ans, total);
                }
            }
        }

        return ans;
    }
};