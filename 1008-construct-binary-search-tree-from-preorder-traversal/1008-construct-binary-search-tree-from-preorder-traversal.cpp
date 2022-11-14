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
    TreeNode *createBST(vector<int> &preorder, int &idx, int val = INT_MAX) {
        if (idx == preorder.size() || preorder[idx] > val) {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[idx++]);
        
        node -> left = createBST(preorder, idx, node -> val);
        node -> right = createBST(preorder, idx, val);
        
        return node; 
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return createBST(preorder, i);
    }
};