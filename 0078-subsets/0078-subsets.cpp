class Solution {
public:
    void helper(vector<int>& vec, vector<vector<int>>& ans, vector<int> nums, int idx) {
        ans.push_back(vec);
        
        for(int i = idx; i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            helper(vec, ans, nums, i + 1);
            vec.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        
        helper(vec, ans, nums, 0);
        
        return ans;
    }
};

