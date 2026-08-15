class Solution {
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int target, int i) {
        int n = nums.size();
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(i == n || target < 0) return;
        curr.push_back(nums[i]);
        helper(nums, curr, ans, target-nums[i], i);
        curr.pop_back();
        helper(nums, curr, ans, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(nums, curr, ans, target, 0);
        return ans;
    }
};
