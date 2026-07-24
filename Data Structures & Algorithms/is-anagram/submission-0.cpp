class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;
        for(int i = 0;i<n;i++) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }
        if(freqS == freqT) {
            return true;
        }
        return false;
    }
};
