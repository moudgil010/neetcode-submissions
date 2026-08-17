class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        if(nums[0] == 0) return -1;

        int farthest = nums[0];
        int currEnd = 0;
        int jumps = 0;
        for(int i=0;i<n-1;i++) {
            farthest = max(farthest, i+nums[i]);
            if(currEnd == i) {
                jumps++;
                currEnd = farthest;
                if(currEnd >= n-1) return jumps;
            }
        }
        return -1;
    }
};
