class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = INT_MIN;

            for (int i = 0; i < n && ok; i += k) {
                int mn = nums[i], mx = nums[i];
                int desc = 0;

                for (int j = i; j < i + k; ++j) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > i && nums[j - 1] > nums[j])
                        ++desc;
                }

                if (nums[i + k - 1] > nums[i])
                    ++desc;

                if (desc > 1 || prevMax > mn)
                    ok = false;

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};