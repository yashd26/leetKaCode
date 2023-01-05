class Solution {
public:
    void helper(int index, vector<int> nums, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            helper(index + 1, nums, result);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(0, nums, result);
        
        return result;
    }
};