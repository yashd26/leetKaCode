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
    int count = 0;
    void helper(TreeNode *root, int max_val) {
        if (!root) {
            return;
        }
        if (root -> val >= max_val) {
            count++;
            max_val = root -> val;
        }
        
        helper(root -> left, max_val);
        helper(root -> right, max_val);
        
        return;
    }
    
    int goodNodes(TreeNode* root) {
        helper(root, root -> val);
        
        return count;
    }
};