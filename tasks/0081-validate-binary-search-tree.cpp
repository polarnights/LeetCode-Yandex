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
    bool isValidBST(TreeNode *root, int64_t right = LLONG_MAX,
                    int64_t left = LLONG_MIN) {
        if (root == NULL) {
            return true;
        }
        if (root->val < right && root->val > left) {
            return isValidBST(root->left, root->val, left) &&
                   isValidBST(root->right, right, root->val);
        }
        return false;
    }
};