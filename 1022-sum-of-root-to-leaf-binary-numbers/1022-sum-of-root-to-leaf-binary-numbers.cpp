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
    int sum = 0;
    void helper(TreeNode *root, int buff) {
        if (!root) {
            return;
        }
        
        buff = (2 * buff) + root -> val;
        if (!root -> left && !root -> right) {
            sum += buff;
            return;
        }
    
        helper(root -> left, buff);
        helper(root -> right, buff);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        
        return sum;
    }
};