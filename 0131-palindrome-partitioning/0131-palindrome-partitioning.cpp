class Solution {
public:
    bool isPalindrome(string str, int start, int end){
        while(start < end) {
            if(str[start++] != str[end--]) {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(int idx, int n, string s, vector<vector<string>>& ans, vector<string>& output) {
        if(idx >= n) {
            ans.push_back(output);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            if(isPalindrome(s, idx, i)) {
                output.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, n, s, ans, output);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> output;
        
        solve(0, n, s, ans, output);
        
        return ans;
    }
};