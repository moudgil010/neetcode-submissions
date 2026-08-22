class Solution {
public:
    int helper(vector<int> &prices, int n, int buy, vector<vector<int>> &dp, int x) {
        if(x >= n) return 0;
        int profit = 0;
        if(dp[x][buy] != -1) return dp[x][buy];
        if(buy) {
            profit = max(-prices[x] + helper(prices, n, 0, dp, x+1), 0 + helper(prices, n, 1, dp, x+1));
        }
        else {
            profit = max(prices[x]+helper(prices, n, 1, dp, x+2), 0 + helper(prices, n, 0, dp, x+1));
        }
        return dp[x][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(prices, n, 1, dp, 0);
    }
};
