class Solution {
public:
    void helper(int idx, vector<int> nums, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); ++i) {
            if (nums[idx] == nums[i] && i != idx) {
                continue;
            }
            swap(nums[i], nums[idx]);
            helper(idx + 1, nums, res);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, res);
        
        return res;
    }
};