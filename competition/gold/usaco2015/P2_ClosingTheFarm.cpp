//
// Created by WillJ on 3/31/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define INF 2000000000
#define MAX_FARMCNT 200000

using namespace std;

struct UnionFind {
    int n;
    vector<int> parent;
    vector<int> depth;
    /**
     * Initializes default values in O(N)
     *
     * @param size Amount of nodes
     */
    void construct(int size) {
        n = size;
        parent = vector<int>(n + 1, 0);
        depth = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            depth[i] = 1;
        }
    }
    /**
     * Gets the highest parent of the node in O(logN)
     *
     * @param node The node to be checked
     * @return The highest parent of the node
     */
    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    /**
     * Connects the two nodes in O(logN)
     *
     * @param a Node one
     * @param b Node two
     */
    void join(int a, int b) {
        int parA = find(a), parB = find(b);
        if (parA == parB) return;
        if (depth[parA] < depth[parB]) parent[parA] = parB;
        else if (depth[parB] < depth[parA]) parent[parB] = parA;
        else {
            parent[parA] = parB;
            depth[parB]++;
        }
    }
};

vector<int> connections[MAX_FARMCNT + 1];
int openingOrder[MAX_FARMCNT]; //reverse closing order
bool open[MAX_FARMCNT + 1];
bool connected[MAX_FARMCNT];

int main() {

    ifstream cin ("closing.in");
    ofstream cout ("closing.out");

    int barnCount, pathCount; cin >> barnCount >> pathCount;
    for (int i = 0; i < pathCount; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for (int i = barnCount - 1; i >= 0; i--) {
        cin >> openingOrder[i];
    }
    UnionFind unionFind{}; unionFind.construct(barnCount);
    int compCount = 0;
    for (int i = 0; i < barnCount; i++) {
        int barn = openingOrder[i];
        open[barn] = true;
        compCount++;
        for (int j : connections[barn]) {
            if (open[j] && (unionFind.find(barn) != unionFind.find(j))) {
                unionFind.join(barn, j);
                compCount--;
            }
        }
        connected[i] = (compCount <= 1);
    }
    for (int i = barnCount - 1; i >= 0; i--) {
        cout << ((connected[i])? "YES" : "NO") << endl;
    }
    return 0;
}
