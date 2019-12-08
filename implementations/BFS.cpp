//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <queue>

#define N 1000

using namespace std;

vector<int> connections[N + 1];

namespace bfs {
    struct State {
        int node;
    };

    bool visited[N + 1];
    /**
     * Runs breadth-first-search
     * @param start Starting node
     */
    void run(int start) {
        queue<State> q;
        q.push(State{start});
        while (!q.empty()) {
            State cur = q.front(); q.pop();
            if (visited[cur.node]) continue;
            visited[cur.node] = true;
            for (int i = 0; i < connections[cur.node].size(); i++) {
                q.push(State{connections[cur.node][i]});
            }
        }
    }
}
