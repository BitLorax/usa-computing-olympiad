//
// Created by WillJ on 1/2/2019.
//

#include <iostream>
#include <vector>

#define INF 2000000000
#define N 1000

using namespace std;

struct Edge {
    int a, b, weight;
};

namespace bellmanFord {
    int dists[N + 1];
    /**
     * Calculates minimum distance from start node to all other nodes in O(NE)
     * @param edges Edges in the graph
     * @param start Starting node
     * @return Returns whether there is a shortest path (false for negative cycle)
     */
    bool run(vector<Edge> &edges, int start) {
        //try optimized version with "Shortest Path Faster Algorithm"
        for (int i = 0; i <= N; i++) dists[i] = INF;
        dists[start] = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < edges.size(); j++) {
                Edge cur = edges[j];
                if (dists[cur.a] != INF) dists[cur.b] = min(dists[cur.b], dists[cur.a] + cur.weight);
            }
        }
        //check for negative cycle
        for (int i = 0; i < edges.size(); i++) {
            Edge cur = edges[i];
            if (dists[cur.a] != INF && dists[cur.a] + cur.weight < dists[cur.b]) return false;
        }
        return true;
    }
}