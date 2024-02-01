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
class BSTIterator {
  private:
    vector<TreeNode *> order;

  public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            order.push_back(root);
            root = root->left;
        }
    }

    int next() {
        auto cur = order.back();
        int val = cur->val;
        order.pop_back();
        if (cur->right == NULL) {
            return val;
        }
        cur = cur->right;
        while (cur != NULL) {
            order.push_back(cur);
            cur = cur->left;
        }
        return val;
    }

    bool hasNext() { return !order.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */