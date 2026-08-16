class Solution {
public:
    // Memoization:

    // vector<int> dp;
    // int helper(int n) {
    //     if(n<=1) return 1;
    //     if(dp[n] != -1) {
    //         return dp[n];
    //     }
    //     return dp[n] = helper(n-1) + helper(n-2);
    // }
    int climbStairs(int n) {
        // dp.resize(n+1, -1);
        // return helper(n);

        // bottom-up approach:
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
