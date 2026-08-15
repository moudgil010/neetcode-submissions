class Solution {
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int target, int i) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(i == n || target < 0) return;
        curr.push_back(nums[i]);
        helper(nums, curr, ans, target-nums[i], i+1);
        curr.pop_back();
        int idx = i+1;
        while(idx < n && nums[idx] == nums[idx-1]) {
            idx++;
        }
        helper(nums, curr, ans,target, idx);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(candidates, curr, ans, target, 0);
        return ans;
    }
};
