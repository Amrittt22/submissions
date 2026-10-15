class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                int n = st.size();
                ans+=n*n;
            }
        }
        return ans;
    }
};