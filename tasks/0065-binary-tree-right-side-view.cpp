#include <deque>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  private:
    deque<TreeNode *> order;
    vector<int> result;

  public:
    void bfs() {
        while (!order.empty()) {
            result.push_back(order.front()->val);
            auto last = order.back();
            while (order.front() != last) {
                if (order.front()->right != NULL) {
                    order.push_back(order.front()->right);
                }
                if (order.front()->left != NULL) {
                    order.push_back(order.front()->left);
                }
                order.pop_front();
            }
            if (order.front()->right != NULL) {
                order.push_back(order.front()->right);
            }
            if (order.front()->left != NULL) {
                order.push_back(order.front()->left);
            }
            order.pop_front();
        }
    }

    vector<int> rightSideView(TreeNode *root) {
        if (root == NULL) {
            return {};
        }
        result.reserve(100);
        order.push_back(root);
        bfs();
        return result;
    }
};