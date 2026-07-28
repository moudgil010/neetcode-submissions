class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto &str:strs) {
            for(auto &ch:str) {
                s.push_back(ch);
            }
            s.push_back((char)0xFF);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string cur = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] == (char)0xFF) {
                res.push_back(cur);
                cur = "";
            }else {
                cur.push_back(s[i]);
            }
        }
        return res;
    }
};
