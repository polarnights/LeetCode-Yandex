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
  private:
    bool result = false;

  public:
    void hasPathSumHelper(TreeNode *cur, int &targetSum, int cur_sum = 0) {
        if (result)
            return;
        cur_sum += cur->val;
        if (cur->left == NULL && cur->right == NULL) {
            result = (cur_sum == targetSum);
            return;
        }
        if (cur->left != NULL) {
            hasPathSumHelper(cur->left, targetSum, cur_sum);
        }
        if (cur->right != NULL) {
            hasPathSumHelper(cur->right, targetSum, cur_sum);
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;
        hasPathSumHelper(root, targetSum);
        return result;
    }
};