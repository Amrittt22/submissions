class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] % 3 == 0)
                cnt0++;
            else if (stones[i] % 3 == 1)
                cnt1++;
            else
                cnt2++;
        }
        if (cnt0 % 2 == 0) {
            if (cnt1 > 0 && cnt2 > 0) {
                return true;
            }
            return false;
        }
        if (abs(cnt1 - cnt2) > 2) {
            return true;
        }
        return false;
    }
};