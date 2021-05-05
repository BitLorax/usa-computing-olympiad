//
// Created by WillJ on 12/27/2018.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define MAX_JUNCCNT 500
#define MAX_PIPECNT 500

using namespace std;

struct Pipe {
    int dest, lat, cap;
};
struct State {
    int junc, lat, cap;
};

vector<Pipe> pipes[MAX_PIPECNT];
int visited[MAX_JUNCCNT + 1];

int main() {
    int junctionCount, pipeCount, milk; cin >> junctionCount >> pipeCount >> milk;
    for (int i = 0; i < pipeCount; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        pipes[a].push_back(Pipe{b, c, d});
        pipes[b].push_back(Pipe{a, c, d});
    }
    for (int i = 1; i <= junctionCount; i++) visited[i] = -1;
    int minTime = INF;
    queue<State> q;
    q.push(State{1, 0, INF});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.junc == junctionCount) {
            minTime = min(minTime, cur.lat + (milk / cur.cap));
            continue;
        }
        if (visited[cur.junc] > -1 && cur.lat + (milk / cur.cap) > visited[cur.junc]) continue;
        visited[cur.junc] = cur.lat + (milk / cur.cap);
        for (int i = 0; i < pipes[cur.junc].size(); i++) {
            q.push(State{pipes[cur.junc][i].dest, cur.lat + pipes[cur.junc][i].lat, min(cur.cap, pipes[cur.junc][i].cap)});
        }
    }
    cout << minTime << endl;
    return 0;
}
