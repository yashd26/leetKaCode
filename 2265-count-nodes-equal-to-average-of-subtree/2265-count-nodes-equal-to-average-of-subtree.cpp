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

    void helper(TreeNode *root, int &sum, int &n) {
        if (!root) {
            return;
        }

        sum += root -> val;
        n += 1;
        helper(root -> left, sum, n);
        helper(root -> right, sum, n);
    }

    void helper1(TreeNode *root) {
        if (!root) {
            return;
        }

        int sum = 0, n = 0;
        helper(root, sum, n);
        if (sum / n == root -> val) {
            count += 1;
        }
        helper1(root -> left);
        helper1(root -> right);
    }

    int averageOfSubtree(TreeNode* root) {
        helper1(root);
        return count;
    }
};