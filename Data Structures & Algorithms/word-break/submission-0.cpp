class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int maxLen = 0;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for(string &word : wordDict) {
            maxLen = max(maxLen, (int)word.length());
        }
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1;i<=n;i++) {
            for(int j=i-1;j>=max(0,i-maxLen);j--) {
                if(dp[j] && st.count(s.substr(j,i-j))) {
                    dp[i] = true;
                    break;
                }
            } 
        }
        return dp[n];
    }
};
