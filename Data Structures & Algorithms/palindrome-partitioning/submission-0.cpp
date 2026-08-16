class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void helper(string s, vector<string> &curr, vector<vector<string>> &ans) {
        if(s.size() == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<s.size();i++) {
            string st = s.substr(0, i+1);
            if(isPalindrome(st)) {
                curr.push_back(st);
                helper(s.substr(i+1), curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, curr, ans);
        return ans;
    }
};
