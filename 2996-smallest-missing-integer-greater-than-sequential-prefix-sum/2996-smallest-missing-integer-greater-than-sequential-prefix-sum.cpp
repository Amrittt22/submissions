class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixsum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                prefixsum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=prefixsum;
        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};