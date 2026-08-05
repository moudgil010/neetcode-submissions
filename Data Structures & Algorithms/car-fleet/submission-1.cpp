class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = make_pair(position[i], (double)(target - position[i])/speed[i]);
        }
        stack<double> st;
        sort(ans.begin(), ans.end());
        for(int i=n-1;i>=0;i--) {
            if(st.empty() || st.top() < ans[i].second) {
                st.push(ans[i].second);
            }
        }
        return st.size();
    }
};
