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
    int getMinimumDifference(TreeNode *root, int current_max = INT_MAX) {
        if (root != NULL) {
            if (root->left != NULL) {
                auto tmp = root->left;
                while (tmp->right != NULL) {
                    tmp = tmp->right;
                }
                current_max = min(current_max, root->val - tmp->val);
            }
            if (root->right != NULL) {
                auto tmp = root->right;
                while (tmp->left != NULL) {
                    tmp = tmp->left;
                }
                current_max = min(current_max, -root->val + tmp->val);
            }
            return min(getMinimumDifference(root->right, current_max),
                       getMinimumDifference(root->left, current_max));
        }
        return current_max;
    }
};