class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> vec, int idx) {
        if (!target) {
            res.push_back(vec);
            return;
        }
        if (target < 0) {
            return;
        }
        
        for(int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            vec.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, vec, i + 1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> vec;
        
        helper(candidates, target, res, vec, 0);
        
        return res;
    }
};