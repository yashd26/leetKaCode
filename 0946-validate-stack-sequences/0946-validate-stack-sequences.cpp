class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        
        for(int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while(!st.empty() && popped[idx] == st.top() && idx < popped.size()) {
                st.pop();
                idx++;
            }
        }
        
        if (st.empty()) {
            return true;
        }
        return false;
    }
};