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
    int max_height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(max_height(root -> left), max_height(root -> right)) + 1;
    }
    
    int sum = 0;
    int sum_at_max(TreeNode* root, int height) {        
        if (!root) {
            return sum;
        }
        if (height == 0) {
            sum = sum + root -> val;
        }
        
        sum_at_max(root -> left, height - 1);
        sum_at_max(root -> right, height - 1);
        
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = max_height(root);
        
        int sum = sum_at_max(root, height - 1);
        return sum;
    }
};