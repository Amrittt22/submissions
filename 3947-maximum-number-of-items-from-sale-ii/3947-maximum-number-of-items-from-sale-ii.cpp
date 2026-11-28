class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        vector<int> freq(maxFactor + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        for (int i = 1; i <= maxFactor; i++) {
            for (int j = 2 * i; j <= maxFactor; j += i) {
                freq[i] += freq[j];
            }
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price >= 2LL * minPrice) break;

            int gain = freq[factor] - 1;

            if (gain <= 0) continue;

            long long take = min((long long)gain, remaining / price);

            ans += 2 * take;
            remaining -= take * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};
