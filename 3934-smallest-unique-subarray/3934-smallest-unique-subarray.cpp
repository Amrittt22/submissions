class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums){
        int n = nums.size();

        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE = 911382323;
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i - 1] * BASE) % MOD1;
            p2[i] = (p2[i - 1] * BASE) % MOD2;
        }

        auto check = [&](int k) -> bool {

            unordered_map<long long, int> freq;

            long long h1 = 0, h2 = 0;

            for (int i = 0; i < k; i++) {
                h1 = (h1 * BASE + nums[i]) % MOD1;
                h2 = (h2 * BASE + nums[i]) % MOD2;
            }

            long long key = h1 * MOD2 + h2;
            freq[key]++;

            for (int i = k; i < n; i++) {

                h1 = (h1 - nums[i - k] * p1[k - 1] % MOD1 + MOD1) % MOD1;
                h2 = (h2 - nums[i - k] * p2[k - 1] % MOD2 + MOD2) % MOD2;

                h1 = (h1 * BASE + nums[i]) % MOD1;
                h2 = (h2 * BASE + nums[i]) % MOD2;

                key = h1 * MOD2 + h2;
                freq[key]++;
            }


            for (auto &it : freq) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
