/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  private:
    unordered_map<int, Node *> visited;
    deque<pair<Node *, Node *>> bfs_queue;

  public:
    void bfs() {
        while (!bfs_queue.empty()) {
            // cout << "[START bfs working\n";
            auto cur = bfs_queue.front();
            // cout << cur.first->val << " END]\n";
            bfs_queue.pop_front();
            for (auto neighbour : cur.second->neighbors) {
                if (visited.contains(neighbour->val)) {
                    cur.first->neighbors.push_back(visited[neighbour->val]);
                    // cout << "Already found\n";
                } else {
                    Node *new_node = new Node(neighbour->val);
                    visited[new_node->val] = new_node;
                    bfs_queue.push_back({new_node, neighbour});
                    // cout << "Inserting val = " << new_node->val << " to queue
                    // from " << cur.first->val << "\n";
                    cur.first->neighbors.push_back(new_node);
                }
            }
        }
    }
    Node *cloneGraph(Node *node) {
        if (node == NULL) {
            return NULL;
        }
        Node *start = new Node(node->val);
        visited[node->val] = start;
        bfs_queue.push_back({start, node});
        bfs();
        return start;
    }
};