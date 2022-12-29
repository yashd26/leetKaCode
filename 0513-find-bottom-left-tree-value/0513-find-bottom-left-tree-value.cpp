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
    bool updated = false;
    int maxHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        return max(maxHeight(root -> left), maxHeight(root -> right)) + 1;
    }
    
    void helper(TreeNode *root, int& res, int h) {
        if (!root) {
            return;
        }
        if (h == 1) {
            res = root -> val;
            updated = true;
            return;
        }
        
        helper(root -> left, res, h - 1);
        if (updated) {
            return;
        }
        helper(root -> right, res, h - 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int h = maxHeight(root);
        int res = 0;
        
        helper(root, res, h);
        
        return res;
    }
};