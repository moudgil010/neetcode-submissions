class Solution {
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int i) {
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(nums, curr, ans, i+1);
        curr.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }
        helper(nums, curr, ans, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(nums, curr, ans, 0);
        return ans;
    }
};
