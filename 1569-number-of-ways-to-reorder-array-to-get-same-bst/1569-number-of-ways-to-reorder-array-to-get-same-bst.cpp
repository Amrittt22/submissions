
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<long long>> C;

    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return 1;
        }

        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        long long interleavings =
            C[left.size() + right.size()][left.size()];

        return interleavings * leftWays % MOD
               * rightWays % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        C.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1]
                         + C[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
