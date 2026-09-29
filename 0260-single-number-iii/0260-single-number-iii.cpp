class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll=0;
        for(int num:nums){
            xorAll^=num;
        }
        long bit=xorAll & (-xorAll);
        int a=0;
        int b=0;
        for(int num:nums){
            if(num & bit){
                a^=num;
            }
            else{
                b^=num;
            }
        }
        return{a,b};
    }
};