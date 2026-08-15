class Solution {
public:
    void helper(vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans, int i) {
        if(i==arr.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        helper(arr, curr, ans, i+1);
        
        curr.pop_back();
        helper(arr, curr, ans, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, curr, ans, 0);
        return ans;
    }
};
