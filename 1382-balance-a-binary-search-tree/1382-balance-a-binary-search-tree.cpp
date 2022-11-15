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
    vector<int> inorderVec;
    TreeNode *createBalBST(vector<int> vec, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(inorderVec[mid]);
        
        node -> left = createBalBST(vec, start, mid - 1);
        node -> right = createBalBST(vec, mid + 1, end);
        
        return node;
    }
    
    void createInorder(TreeNode *root) {
        if (!root) {
            return;
        }
        createInorder(root -> left);
        inorderVec.push_back(root -> val);
        createInorder(root -> right);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        createInorder(root);
        return createBalBST(inorderVec, 0, inorderVec.size() - 1);
    }
};