class Solution {
public:
    vector<int> vec;
    void findPath(vector<vector<int>> graph, int idx, vector<vector<int>> &ans, int target) {
        vec.push_back(idx);
        if (idx == target) {
            ans.push_back(vec);
        }
        else {
            for(int val: graph[idx]) {
                findPath(graph, val, ans, target);
            }
        }
        vec.pop_back();
    }
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        findPath(graph, 0, ans, graph.size() - 1);
        
        return ans;
    }
};