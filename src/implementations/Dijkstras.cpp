//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
#define N 1000

using namespace std;

struct State {
    int node, len;
    bool operator<(const State &a) const {
        return len > a.len;
    }
};

int dists[N + 1];
vector<pair<int, int>> connections[N + 1];

void dijkstras(vector<pair<int, int>> connections[], int start) {
    priority_queue<State> q;
    q.push(State{start, 0});
    while (!q.empty()) {
        State cur = q.top(); q.pop();
        if (dists[cur.node] != -1) continue;
        dists[cur.node] = cur.len;
        for (int i = 0; i < connections[cur.node].size(); i++) {
            q.push(State{connections[cur.node][i].first, cur.len + connections[cur.node][i].second});
        }
    }
}

int main() {
    for (int i = 0; i <= N; i++) dists[i] = -1;
    return 0;
}
