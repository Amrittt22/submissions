class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int profit=0;
        int buy=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else if(prices[i]>buy+fee){
                profit+=prices[i]-fee-buy;
                buy=prices[i]-fee;
            }
        }
        return profit;
    }
};