#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, size_t> index_finder;
    vector<int> elements;
public:
    RandomizedSet() {
        index_finder = {};
        elements = {};
    }
    
    bool insert(int val) {
        if (!index_finder.count(val)) {
            index_finder[val] = elements.size();
            elements.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (index_finder.count(val)) {
            auto idx = index_finder[val];
            if (idx == elements.size() - 1) {
                index_finder.erase(val);
                elements.pop_back();
                return true;
            }
            auto tmp = index_finder[elements.back()]; // index of last elem
            elements[idx] = elements[tmp];
            index_finder[elements.back()] = idx;
            index_finder.erase(val);
            elements.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // TODO: Is it possible to store rd and gen?
        // TODO: How good it is to use C-style rand()? Can one change RAND_MAX and is the distribution "fair"?
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution(0, elements.size() - 1);
        return elements[distribution(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */