class Solution {
public:
    bool isFreqSame(int frq1[], int frq2[]) {
        for(int i=0;i<26;i++) {
            if(frq1[i] != frq2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int hash[26] = {0};
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;i++) {
            hash[s1[i] - 'a']++;
        }

        for(int i=0;i<m;i++) {
            int size = 0;
            int j=i;
            int freq[26] = {0};
            while(size < n && j < m) {
                freq[s2[j] - 'a']++;
                size++;
                j++;
            }
            if(isFreqSame(hash, freq)) {
                return true;
            }
        }
        return false;
    }
};
