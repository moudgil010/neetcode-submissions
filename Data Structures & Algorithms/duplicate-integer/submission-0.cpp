class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
        }
        for(const auto& num : freq) {
            if(num.second > 1) {
                return true;
            }
        }
        return false;
    }
};