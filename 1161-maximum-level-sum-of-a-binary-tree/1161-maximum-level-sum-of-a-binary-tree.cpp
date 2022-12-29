/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = INT_MIN, maxSum = INT_MIN, lvl = 0;
    int maxHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        return max(maxHeight(root -> left), maxHeight(root -> right)) + 1;
    }
    
    void helper(TreeNode *root, int h) {
        if (!root) {
            return;
        }
        if (h == 1) {
            sum += root -> val;
        }
        
        helper(root -> left, h - 1);
        helper(root -> right, h - 1);
    }
    
    int maxLevelSum(TreeNode* root) {
        int h = maxHeight(root);
        
        for(int i = 1; i <= h; ++i) {
            sum = 0;
            helper(root, i);
            if (sum > maxSum) {
                lvl = i;
                maxSum = sum;
            }
        }
        
        return lvl;
    }
};