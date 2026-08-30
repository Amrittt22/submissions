class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int maxIndex = -1;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                maxIndex = i;
            }
            if (nums[i] == mini) {
                minIndex = i;
            }
        }
        int a = min(maxIndex,minIndex);
        int b = max(maxIndex,minIndex);
        int left = b + 1;
        int right = n - a;
        int both = (a + 1) + (n - b);

        return min({left, right, both});
    }
};