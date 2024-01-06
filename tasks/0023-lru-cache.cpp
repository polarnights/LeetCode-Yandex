#include <deque>
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
    class Node {
      public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node() : key(0), value(0), next(nullptr), prev(nullptr) {}

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

  private:
    unordered_map<int, Node *> storage_;
    int capacity_ = 0;
    int size = 0;
    // We need to create our own deque with a
    // proper O(1) deletion of the elements
    // when we want to update the queue
    Node *head = new Node();
    Node *tail = new Node();

  public:
    LRUCache(int capacity) : capacity_(capacity) {
        // Head->next = LRU
        // Tail->prev = Last used (the most recent one)
        head->next = tail;
        tail->next = head;
        head->prev = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (storage_.contains(key)) {
            // Change the order here
            // cout << "DEBUG | Started attempt to change order with GET | prev
            // "
            //         "LRU = "
            //      << head->next->key << "\n";
            Node *current = storage_[key];
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // ---
            tail->prev->next = current;
            current->prev = tail->prev;
            current->next = tail;
            tail->prev = current;
            // Is the next line even needed?
            storage_[key] = current;
            // cout
            //     << "DEBUG | Ended attempt to change order with GET | now LRU
            //     = "
            //     << head->next->key << "\n";
            return storage_[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (storage_.contains(key)) {
            // Change the order here
            Node *current = storage_[key];
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // ---
            tail->prev->next = current;
            current->prev = tail->prev;
            current->next = tail;
            tail->prev = current;
            // Is the next line even needed?
            current->value = value;
            storage_[key] = current;
        } else {
            size++;
            // cout << "DEBUG | No-key put case | size = " << size
            //     << ", capacity_ = " << capacity_ << "\n";
            if (size > capacity_) {
                auto lru_node = head->next;
                head->next = lru_node->next;
                lru_node->next->prev = head;
                storage_.erase(lru_node->key);
                // cout << "DEBUG | Erasing node (key, value) = (" <<
                // lru_node->key
                //      << "," << lru_node->value << ")\n";
                // delete lru_node;
                size--;
            }
            Node *current = new Node(key, value);
            storage_[key] = current;
            tail->prev->next = current;
            current->prev = tail->prev;
            current->next = tail;
            tail->prev = current;
        }
    }

    void debug_helper() {
        cout << "[ (k/v)s = ";
        for (auto &elem : storage_) {
            cout << "(" << elem.second->key << "," << elem.second->value
                 << ") ";
        }
        cout << ")\n";
    }
};

int
main() {

    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);   // cache is {1=1}
    lRUCache->put(2, 2);   // cache is {1=1, 2=2}
    lRUCache->debug_helper();
    cout << lRUCache->get(1) << "\n";   // return 1
    lRUCache->put(3, 3);   // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << "\n";   // returns -1 (not found)
    lRUCache->put(4, 4);   // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << "\n";   // return -1 (not found)
    cout << lRUCache->get(3) << "\n";   // return 3
    cout << lRUCache->get(4) << "\n";   // return 4
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */