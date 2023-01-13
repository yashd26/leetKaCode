class Solution {
public:
    bool helper(int idx, vector<vector<int>>& graph, vector<int>& vis) {
        if (vis[idx] == -1) {
            vis[idx] = 0;
        }
        
        for(int i = 0; i < graph[idx].size(); ++i) {
            if (vis[graph[idx][i]] == -1) {
                vis[graph[idx][i]] = 1 - vis[idx];
                if (!helper(graph[idx][i], graph, vis)) {
                    return false;
                }
            }
            else if(vis[graph[idx][i]] == vis[idx]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); ++i) {
            if (!helper(i, graph, vis)) {
                return false;
            }
        }
        
        return true;
    }
};