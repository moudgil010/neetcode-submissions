class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        if(nums[0] == 0) return false;

        int farthest = nums[0];
        int currEnd = 0;
        for(int i=0;i<n-1;i++) {
            farthest = max(farthest, i+nums[i]);
            if(i==currEnd) {
                currEnd = farthest;
                if(currEnd >= n-1) return true;
            }
        }
        return false;
    }
};
