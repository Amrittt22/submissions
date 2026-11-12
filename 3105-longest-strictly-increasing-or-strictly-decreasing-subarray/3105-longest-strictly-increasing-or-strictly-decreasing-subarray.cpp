class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int icount=1;
        int dcount=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                icount++;
                dcount=1;
            }
            else if (nums[i]<nums[i-1]){
                dcount++;
                icount=1;
            }
            else{
                dcount=1;
                icount=1;
            }
            ans=max(ans,max(icount,dcount));
        }
        return ans;
    }
};