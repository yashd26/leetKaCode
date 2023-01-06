class Solution {
public:
    void helper(vector<vector<int>>& vec, int idx, vector<int>& vis) {
        vis[idx] = 1;
        
        for(auto ele: vec[idx]) {
            if (!vis[ele]) {
                helper(vec, ele, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) {
            return -1;
        }
        
        vector<vector<int>> vec(n);
        vector<int> vis(n, 0);
        int cnt = 0;
        
        for(auto ele: connections) {
            vec[ele[0]].push_back(ele[1]);
            vec[ele[1]].push_back(ele[0]);
        }
        
        for(int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                helper(vec, i, vis);
            }
        }
        
        return cnt - 1;
    }
};