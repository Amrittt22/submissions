class Solution {
public:
    multiset<int> left, right;
    long long sumL = 0, sumR = 0;

    void balance() {
        int target = (left.size() + right.size() + 1) / 2;

        while (left.size() > target) {
            auto it = prev(left.end());
            int val = *it;

            left.erase(it);
            sumL -= val;

            right.insert(val);
            sumR += val;
        }

        while (left.size() < target) {
            auto it = right.begin();
            int val = *it;

            right.erase(it);
            sumR -= val;

            left.insert(val);
            sumL += val;
        }
    }

    void add(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
            sumL += num;
        } else {
            right.insert(num);
            sumR += num;
        }

        balance();
    }

    void remove(int num) {
        auto it = left.find(num);

        if (it != left.end()) {
            left.erase(it);
            sumL -= num;
        } else {
            it = right.find(num);
            right.erase(it);
            sumR -= num;
        }

        balance();
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumL + sumR - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        left.clear();
        right.clear();
        sumL = sumR = 0;

        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};