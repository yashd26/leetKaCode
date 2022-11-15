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
    vector<int> vec;
    TreeNode *createTree(vector<int> vec, int idx) {
        if (idx > vec.size() - 1) {
            return NULL;
        }
        TreeNode *node = new TreeNode(vec[idx]);
        node -> right = createTree(vec, idx + 1);
        
        return node;
    }
    
    void createInorder(TreeNode *root) {
        if (!root) {
            return;
        }
        createInorder(root -> left);
        vec.push_back(root -> val);
        createInorder(root -> right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        createInorder(root);
        return createTree(vec, 0);
    }
};