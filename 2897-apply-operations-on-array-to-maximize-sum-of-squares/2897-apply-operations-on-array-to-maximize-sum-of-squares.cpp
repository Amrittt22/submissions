class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long mod = 1e9+7;
        vector<int>count(31,0);
        for(int i=0;i<n;i++){
            for(int bits=0;bits<31;bits++){
                if((nums[i]>>bits)&1){
                    count[bits]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            long long num=0;
            for(int bits=0;bits<31;bits++){
                if(count[bits]>0){
                    num|=(1LL<<bits);
                    count[bits]--;
                }
            }
            ans=(ans+num*num)%mod;
        }   
        return ans;
    }
};