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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root -> left) {
            TreeNode *tempNode = removeLeafNodes(root -> left, target);
            root -> left = tempNode;
        }
        if (root -> right) {
            TreeNode *tempNode = removeLeafNodes(root -> right, target);
            root -> right = tempNode;
        }
        if (!root -> right && !root -> left && root -> val == target) {
            return NULL;
        }
        
        return root;
    }
};