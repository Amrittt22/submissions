class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int n=prices.size();
        int minP=INT_MAX;
        for(int i=0;i<n;i++){
            minP=min(minP,prices[i]);
            maxP=max(maxP,prices[i]-minP);
        }
        return maxP;
    }
};