class Solution {
public:
    void helper(int open, int close, string curr, vector<string> &ans) {
        if(open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }
        if(open > 0) {
            helper(open-1, close, curr+"(", ans);
        }
        if(close > open) {
            helper(open, close-1, curr+")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = n;
        int close = n;
        helper(open, close, curr, ans);
        return ans;
    }
};
