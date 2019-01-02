//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define N 1000

using namespace std;

struct State {
    int node, len, parent;
    bool operator<(const State &a) const {
        return len > a.len;
    }
};

int parent[N + 1];

//Prim's
int prims(vector<pair<int, int>> &connections[]) {
    int len = 0;
    priority_queue<State> q;
    q.push(State{1, 0, 1});
    while (!q.empty()) {
        State cur = q.top(); q.pop();
        if (parent[cur.node] != 0) continue;
        parent[cur.node] = cur.parent;
        len += cur.len;
        for (int i = 0; i < connections[cur.node].size(); i++) {
            q.push(State{connections[cur.node][i].first, connections[cur.node][i].second, cur.node});
        }
    }
    return len;
}
//Prim's

int main() {
    return 0;
}
