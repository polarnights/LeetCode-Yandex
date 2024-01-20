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
    void invertCurrent(TreeNode *cur) {
        if (cur == NULL || (cur->left == NULL && cur->right == NULL)) {
            return;
        }
        if (cur->left != NULL && cur->right != NULL) {
            auto tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            invertCurrent(cur->left);
            invertCurrent(cur->right);
        } else {
            if (cur->left != NULL) {
                cur->right = cur->left;
                cur->left = NULL;
                invertCurrent(cur->right);
            } else if (cur->right != NULL) {
                cur->left = cur->right;
                cur->right = NULL;
                invertCurrent(cur->left);
            }
        }
    }
    TreeNode *invertTree(TreeNode *root) {
        invertCurrent(root);
        return root;
    }
};