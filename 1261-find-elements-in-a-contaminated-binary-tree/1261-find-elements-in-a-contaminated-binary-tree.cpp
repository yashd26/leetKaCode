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
class FindElements {
public:
    TreeNode *node;
    bool isThere = false;
    
    void createAFuckedUpTree(TreeNode *root) {
        if (!root) {
            return;
        }
        if (root -> left) {
            root -> left -> val = 2 * root -> val + 1;
        }
        if (root -> right) {
            root -> right -> val = 2 * root -> val + 2;
        }
        
        createAFuckedUpTree(root -> left);
        createAFuckedUpTree(root -> right);
    }
    
    FindElements(TreeNode* root) {
        root -> val = 0;
        createAFuckedUpTree(root);
        
        node = root;
    }
    
    void findIt(TreeNode *root1, int target) {
        if (!root1) {
            return;
        }
        if (root1 -> val == target) {
            isThere = true;
        }
        
        if (isThere) {
            return;
        }
        findIt(root1 -> left, target);
        findIt(root1 -> right, target);
    }
    
    bool find(int target) {
        findIt(node, target);
        
        if (isThere) {
            isThere = false;
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */