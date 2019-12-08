
#include <iostream>
#include <vector>

#define N 1000

using namespace std;

namespace unionFind {
    int n;
    int component[N + 1];
    vector<int> indices[N + 1];
    /**
     * Initializes default values in O(N)
     *
     * @param size Amount of nodes
     */
    void construct(int size) {
        n = size;
        for (int i = 0; i <= n; i++) {
            component[i] = i;
            indices[i].push_back(i);
        }
    }
    /**
     * Gets the highest parent of the node in O(1)
     *
     * @param node The node to be checked
     * @return The highest parent of the node
     */
    int find(int node) {
        return component[node];
    }
     /**
      * Connects two nodes in O(logN)
      * @param a Node one
      * @param b Node two
      * @return true if the connection was established, false if the two nodes were already together
      */
    bool join(int a, int b) {
        if (find(a) == find(b)) return false;
        if (indices[component[b]].size() > indices[component[a]].size()) {
            int temp = a;
            a = b; b = temp;
        }
        for (int j : indices[component[b]]) {
            component[j] = component[a];
            indices[component[a]].push_back(j);
        }
        return true;
    }
};
