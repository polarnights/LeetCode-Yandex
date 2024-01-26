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
    int k_;
    int result = INT_MAX;

  public:
    void kthSmallestHelper(TreeNode *root) {
        if (k_ <= 0 || root == NULL)
            return;
        kthSmallestHelper(root->left);
        // cout << "k before edit = " << k_ << "\n";
        k_--;
        if (k_ == 0) {
            result = root->val;
        }
        kthSmallestHelper(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        k_ = k;
        kthSmallestHelper(root);
        return result;
    }
};