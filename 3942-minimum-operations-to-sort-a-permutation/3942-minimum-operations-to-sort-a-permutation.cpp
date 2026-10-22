class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool A = true, B = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) A = false;
            if (nums[i] != ((nums[0] - i) % n + n) % n) B = false;
        }
        if (!A && !B) return -1;
        int ans = INT_MAX;
        if (A) {
            int k = nums[0];
            if (k == 0) ans = 0;
            else ans = min(n - k, k + 2);
        }
        if (B) {
            int k = nums[0];
            int j = (n - nums[n - 1]) % n;
            int a = (k + 1) % n;
            ans = min(ans, 1 + min(j, a));
        }
        return ans;
    }
};