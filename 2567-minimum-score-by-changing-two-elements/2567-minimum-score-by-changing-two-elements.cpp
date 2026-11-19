class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int dropTwoLeft=nums[n-1]-nums[2];
        int dropTwoRight=nums[n-3]-nums[0];
        int dropOneEach=nums[n-2]-nums[1];
        return min({dropTwoLeft,dropTwoRight,dropOneEach});
    }
};