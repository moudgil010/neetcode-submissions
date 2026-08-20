class Solution {
public:
    bool subsetSum(vector<int> &arr, int s) {
        int n = arr.size();
        vector<vector<bool>>t(n+1, vector<bool>(s+1));
        for(int i=0;i<n+1;i++) {
            if(i==0) t[i][0] = true;
        }
        for(int j=1;j<s+1;j++) {
            if(j==0) t[0][j] = false;
        }
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<s+1;j++) {
                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][s];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;
        int s = sum/2;
        return subsetSum(nums, s);
    }
};
