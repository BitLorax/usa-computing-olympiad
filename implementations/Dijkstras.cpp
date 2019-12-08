//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
#define f first
#define s second
#define N 1000

using namespace std;

vector<pair<int, int>> connections[N + 1];

namespace dijkstras {
    struct State {
        int node, len;
        bool operator<(const State &a) const {
            return len > a.len;
        }
    };
    int dists[N + 1];
    /**
     * Runs Dijkstras with starting node
     * @param start Starting node
     */
    void run(int start) {
        for (int i = 0; i < N; i++) dists[i] = -1;

        priority_queue<State> q;
        q.push(State{start, 0});
        while (!q.empty()) {
            State cur = q.top(); q.pop();
            if (dists[cur.node] != -1) continue;
            dists[cur.node] = cur.len;
            for (int i = 0; i < connections[cur.node].size(); i++)
                q.push(State{connections[cur.node][i].f, cur.len + connections[cur.node][i].s});
        }
    }
}
