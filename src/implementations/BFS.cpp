//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define N 1000

using namespace std;

struct State {
    int node;
};

bool visited[N + 1];

//BFS
void BFS(vector<int> &connections[]) {
    queue<State> q;
    q.push(State{1});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (visited[cur.node]) continue;
        visited[cur.node] = true;
        for (int i = 0; i < connections[cur.node].size(); i++) {
            q.push(State{connections[cur.node][i]});
        }
    }
}
//BFS

int main() {
    return 0;
}
