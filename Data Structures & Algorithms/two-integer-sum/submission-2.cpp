class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i]+nums[j] == target) {
                    return {i,j};
                }
            }
        }
        // int i = 0;
        // int j = n-1;
        // while(i<=j) {
        //     if(nums[i]+nums[j] == target) {
        //         return {i,j};
        //     }
        //     else {
        //         if(nums[i]+nums[j] < target) {
        //             i++;
        //         }
        //         else j--;
        //     }
        // }
        return {};
    }
};
