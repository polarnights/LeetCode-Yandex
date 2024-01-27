/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    int result = 0;
    void hasPathSumHelper(TreeNode *cur, int temp = 0) {
        temp *= 10;
        temp += cur->val;
        if (cur->left == NULL && cur->right == NULL) {
            result += temp;
            return;
        }
        if (cur->left != NULL) {
            hasPathSumHelper(cur->left, temp);
        }
        if (cur->right != NULL) {
            hasPathSumHelper(cur->right, temp);
        }
    }

    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        hasPathSumHelper(root);
        return result;
    }
};