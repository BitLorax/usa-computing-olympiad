//
// Created by WillJ on 4/1/2019.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define MOD 2019201997
#define A 2019201913
#define B 2019201949

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

struct Connection {
    int a, b;
    long long dist;
    bool operator<(const Connection &a) const {
        return dist < a.dist;
    }
};

long long multiply(long long a, long long b, long long c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    long a2 = multiply(a, b / 2, c);
    if ((b & 1) == 0) {
        return (a2 + a2) % c;
    } else {
        return ((a % c) + (a2 + a2) % c) % c;
    }
}

unsigned long long getDist(unsigned long long a, unsigned long long b) {
    return (((A * a) - (A * a / MOD) * MOD) + ((B * b) - (B * b / MOD) * MOD)) % MOD;
    //return (((A / 2) * a) % MOD + ((A / 2 + 1) * a) % MOD + (B / 2 * b) % MOD + ((B / 2 + 1 )* b) % MOD) % MOD;
}

vector<Connection> connections;

int main() {

    ifstream cin ("walk.in");
    ofstream cout ("walk.out");

    int cowCount, groupCount; cin >> cowCount >> groupCount;
    for (int i = 1; i <= cowCount; i++) {
        for (int j = 1; j < i; j++) {
            Connection k{j, i, getDist(j, i)};
            connections.push_back(k);
        }
    }
    sort(connections.begin(), connections.end());
    UnionFind unionFind{}; unionFind.construct(cowCount);
    int counter = cowCount - groupCount;
    int i = 0;
    for (i; i < connections.size(); i++) {
        if (counter == 0) break;
        if (unionFind.find(connections[i].a) != unionFind.find(connections[i].b)) {
            unionFind.join(connections[i].a, connections[i].b);
            counter--;
        }
    }
//    for (it; it != connections.end(); it++) {
//        if (counter == 0) break;
//        if (unionFind.find(it->a) != unionFind.find(it->b)) {
//            unionFind.join(it->a, it->b);
//            counter--;
//        }
//    }
    for (i; i < connections.size(); i++) {
        if (unionFind.find(connections[i].a) != unionFind.find(connections[i].b)) {
            cout << connections[i].dist << endl;
            break;
        }
    }
//    for (it; it != connections.end(); it++) {
//        if (unionFind.find(it->a) != unionFind.find(it->b)) {
//            cout << it->dist << endl;
//            break;
//        }
//    }
    return 0;
}
