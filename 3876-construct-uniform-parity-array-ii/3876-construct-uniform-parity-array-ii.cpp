class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int target = nums1[0] % 2;
        bool seenOdd = false;
        for (auto x : nums1) {
            if (x % 2 != target && !seenOdd) {
                return false;
            }
            if (x % 2 == 1) {
                 seenOdd = true;
            }
        }
        return true;
    }
};