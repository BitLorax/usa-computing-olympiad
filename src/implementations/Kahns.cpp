
#include <iostream>
#include <queue>
#include <vector>

#define N 1000

using namespace std;

vector<int> connections[N + 1];


namespace kahns {
    int parents[N + 1];
    /**
     * Computes the topographical sort of a DAG with Kahn's in O(NE)
     * Note: nodes are 0-indexed
     * @param size Number of nodes
     * @return Topographical sort ordering
     */
    vector<int> kahns(int size) {
        vector<int> topographicalSort;
        for (int i = 0; i < size; i++)
            for (int j : connections[i]) parents[j]++;

        queue<int> q;
        for (int i = 0; i < size; i++) if (parents[i] == 0) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            topographicalSort.push_back(cur);
            for (int i : connections[cur]) {
                parents[i]--;
                if (parents[i] == 0) q.push(i);
            }
        }
        return topographicalSort;
    }
}