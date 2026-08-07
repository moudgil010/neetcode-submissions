class Solution {
public:
    int timeT(vector<int> &arr, int m) {
        int n = arr.size();
        int timeReq = 0;
        for(int i=0;i<n;i++) {
            timeReq += ceil((double)arr[i]/m);
        }
        return timeReq;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());
        if(n == h) return maxi;
        int l = 1;
        int r = maxi;
        int mid = l+(r-l)/2;
        int ans = INT_MAX;
        while(l<=r) {
            mid  = l+(r-l)/2;
            int timeTaken = timeT(piles, mid);
            if(timeTaken <= h) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
