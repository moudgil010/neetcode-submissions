class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(auto &ch : tokens) {
            if(ch == "+") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2+temp1);
            }else if(ch == "-") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2-temp1);
            } else if(ch == "*") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2*temp1);
            } else if(ch == "/") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2/temp1);
            }
            else st.push(stoi(ch));
        }
        return st.top();
    }
};
