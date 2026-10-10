class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        const int MAXD = 100000;

        vector<long long> freq(MAXD + 1, 0);
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (k >= total) return 0;

        for (int d = MAXD; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long moves = min(k, freq[d]);
            freq[d] -= moves;
            freq[d - 1] += moves;
            k -= moves;
        }

        long long ans = 0;

        for (int d = 1; d <= MAXD; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};
