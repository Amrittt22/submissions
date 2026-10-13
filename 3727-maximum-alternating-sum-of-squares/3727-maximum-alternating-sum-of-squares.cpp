class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)<abs(b);
        });
        int l = 0, r = n - 1;
        long long pos = 0;
        long long neg = 0;
        while (l <= r) {
            if (l == r)
                pos += (1LL*nums[r] * nums[r]);
            else {
                pos += (1LL* nums[r] * nums[r]);
                neg += (1LL*nums[l] * nums[l]);
            }
            l++;
            r--;
        }
        return pos-neg;
    }
};