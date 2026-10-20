class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold= -prices[0];
        int sold= INT_MIN;
        int rest=0;
        for(int i=0;i<prices.size();i++){
            int prevHold=hold;
            int prevSold=sold;
            int prevRest=rest;

            hold=max(prevHold,prevRest-prices[i]);
            sold=prevHold+prices[i];
            rest=max(prevRest,prevSold);
        }
        return max(sold,rest);
    }
};