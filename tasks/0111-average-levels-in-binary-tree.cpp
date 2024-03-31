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
    deque<pair<TreeNode *, int>> order;
    vector<double> result_vec;

  public:
    void bfs() {
        double result = 0;
        int cur_level = 0;
        int count = 0;
        while (!order.empty()) {
            auto elem = order.front();
            order.pop_front();
            // cout << cur_level << " | " << elem.second << "\n";
            if (cur_level != elem.second) {
                result_vec.push_back(result / count);
                result = 0;
                count = 0;
                cur_level = elem.second;
            }
            result += elem.first->val;
            if (elem.first->left != NULL) {
                order.push_back({elem.first->left, elem.second + 1});
            }
            if (elem.first->right != NULL) {
                order.push_back({elem.first->right, elem.second + 1});
            }
            count++;
        }
        if (count != 0) {
            result_vec.push_back(result / count);
        }
    }

    vector<double> averageOfLevels(TreeNode *root) {
        if (root == NULL) {
            return {};
        }
        order.push_back({root, 0});
        bfs();
        return result_vec;
    }
};