class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for(int i = 0; i < nums.size(); i++) {
            int j = nums.size() - 1;
            int k = i + 1;
        
            while(k < j) {
                if(nums[i] + nums[j] + nums[k] < 0) {
                    k++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    j--;
                }
                else {
                    s.insert({nums[i], nums[j], nums[k]});
                    j--;
                    k++;
                }  
            }
        }
        
        vector<vector<int>> vec;
        for(auto val: s) {
            vec.push_back(val);
        }
            
        return vec;
    }
};