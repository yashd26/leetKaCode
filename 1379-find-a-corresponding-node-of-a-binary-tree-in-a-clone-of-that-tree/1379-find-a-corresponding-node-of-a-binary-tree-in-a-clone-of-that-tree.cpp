/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    
    void get_clone(TreeNode *org_root, TreeNode *clone_root, TreeNode *target) {
        if (org_root) {
            get_clone(org_root -> left, clone_root -> left, target);
            if (org_root == target) {
                res = clone_root;
                return;
            }
            get_clone(org_root -> right, clone_root -> right, target);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        get_clone(original, cloned, target);
        return res;
    }
};