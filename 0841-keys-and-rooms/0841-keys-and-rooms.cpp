class Solution {
public:
    void dfs(vector<vector<int>> graph, int idx, vector<int>& vis) {
        vis[idx] = 1;
        
        for(int i = 0; i < graph[idx].size(); ++i) {
            if (!vis[graph[idx][i]]) {
                dfs(graph, graph[idx][i], vis);
            }
        }
    }
        
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        dfs(rooms, 0, vis);
        
        for(int i = 0; i < vis.size(); ++i) {
            if (!vis[i]) {
                return 0;
            }
        }
        return 1;
    }
};