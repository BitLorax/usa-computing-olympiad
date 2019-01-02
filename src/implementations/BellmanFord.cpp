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

int dists[N + 1];

bool bellmanFord(vector<Edge> &edges, int start) {
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

int main() {
    return 0;
}
