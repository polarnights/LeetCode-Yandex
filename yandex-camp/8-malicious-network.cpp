#include "Network.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <map>
#include <set>
#include <vector>

int
main(int argc, char *argv[]) {
    // 1. Read data from standard input.
    // 2. Construct Network object.
    // 3. Send some packets using getPath(int source, int destination) method to
    // find the edge that contaminates them.
    // 4. Save edge id to standard output.
    int n;
    std::cin >> n;
    std::vector<Edge> temp;
    int max_n = INT_MIN;
    for (int i = 0; i < n; i++) {
        int id, a, b;
        std::cin >> id >> a >> b;
        Edge current;
        current.id = id;
        current.i = a;
        current.j = b;
        temp.push_back(current);
        max_n = std::max(max_n, a);
        max_n = std::max(max_n, b);
    }

    Network nw(temp);

    for (int i = 0; i < n; i++) {
        auto result = nw.getPath(temp[i].i, temp[i].j);
        if (result.isContaminated) {
            std::cout << temp[i].id << "\n";
            return 0;
        }
    }
}
