class Solution {
public:
    int n;
    vector<long long> bitCount;
    vector<long long> bitSum;

    void update(int idx, long long c, long long s) {
        while (idx <= n) {
            bitCount[idx] += c;
            bitSum[idx] += s;
            idx += idx & (-idx);
        }
    }

    long long queryCount(int idx) {
        long long res = 0;
        while (idx > 0) {
            res += bitCount[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    long long querySum(int idx) {
        long long res = 0;
        while (idx > 0) {
            res += bitSum[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007;
        n = nums.size();

        bitCount.assign(n + 1, 0);
        bitSum.assign(n + 1, 0);

        vector<int> lastSeen(100001, 0);

        long long curr = 0;
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int val = nums[i - 1];
            int prev = lastSeen[val];

            long long cnt = queryCount(i - 1) - queryCount(prev);
            long long sm = querySum(i - 1) - querySum(prev);

            long long contribution = sm - 1LL * prev * cnt;

            curr += 2 * contribution + (i - prev);
            ans = (ans + curr) % MOD;

            if (prev > 0) {
                update(prev, -1, -prev);
            }

            update(i, 1, i);
            lastSeen[val] = i;
        }

        return ans;
    }
};