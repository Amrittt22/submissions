class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>Maxprefix(n);
        vector<int>Minsuffix(n);
        Maxprefix[0]=nums[0];
        for(int i=1;i<n;i++){
            Maxprefix[i]=max(Maxprefix[i-1],nums[i]);
        }
        Minsuffix[n-1]=nums[n-1];
        for(int i = n-2 ;i>=0;i--){
            Minsuffix[i]=min(Minsuffix[i+1],nums[i]);
        }
        for(int i=0 ;i<n ;i++){
            if(Maxprefix[i] - Minsuffix[i] <=k){
                return i;
            }
        }
        return -1;
    }
};