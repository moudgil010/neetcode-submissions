class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIndex = -1;
        int hash[256] = {0};
        
        for(auto c : t) {
            hash[c]++;
        }
        while(r<n) {
            if(hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
