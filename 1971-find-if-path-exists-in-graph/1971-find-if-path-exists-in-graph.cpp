class Solution {
public:
    bool helper(vector<vector<int>>& vec, vector<int>& vis, int idx, int val) {
        if (idx == val) {
            return true;
        }
        if (vis[idx]) {
            return false;
        }
        
        vis[idx] = 1;
        for(auto elem: vec[idx]) {
            if(helper(vec, vis, elem, val)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> vec(n);
        
        for(int i = 0; i < edges.size(); i++) {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        return helper(vec, vis, source, destination);
    }
};