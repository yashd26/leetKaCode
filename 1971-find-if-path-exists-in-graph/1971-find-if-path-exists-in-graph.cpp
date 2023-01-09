class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr_node, int end_node) {
        if (curr_node == end_node) {
            return true;
        }
        if (visited[curr_node]) {
            return false;
        }
        
        visited[curr_node] = 1;
        
        for(int i = 0; i < graph[curr_node].size(); i++) {
            if(dfs(graph, visited, graph[curr_node][i], end_node)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        
        for(int i = 0;i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, source, destination);
    }
};