class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int col = 0; col < n; col++) {
            dp[n - 1][col] = triangle[n-1][col];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                int down=dp[row+1][col];
                int diagonal=dp[row+1][col+1];
                dp[row][col]=triangle[row][col] + min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};