class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        
        for(auto var: s) {
            if (var == '(') {
                cnt += 1;
                if (cnt > 1) {
                    ans += '(';    
                }
            }
            else {
                if (cnt > 1) {
                    ans += ")";   
                }
                cnt -= 1;
            }
        }
        
        return ans;
    }
};