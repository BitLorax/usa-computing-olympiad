//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
#define MAX_BARNCNT 100000

using namespace std;

struct State {
    int node, len, starter;
};

vector<int> connections[MAX_BARNCNT + 1];
int dists[MAX_BARNCNT + 1][2]; //[0] is bessie, [1] is farmers
bool visited[MAX_BARNCNT + 1];
bool canCatchAt[MAX_BARNCNT + 1];

int main() {
    int barnCount, start; cin >> barnCount >> start;
    for (int i = 0; i < barnCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    queue<State> q;
    q.push(State{start, 0, 0});
    for (int i = 1; i <= barnCount; i++) {
        if (connections[i].size() == 1) q.push(State{i, 0, 1});
        dists[i][0] = -1; dists[i][1] = -1;
    }

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (dists[cur.node][cur.starter] != -1) continue;
        dists[cur.node][cur.starter] = cur.len;
        for (int i = 0; i < connections[cur.node].size(); i++) {
            q.push(State{connections[cur.node][i], cur.len + 1, cur.starter});
        }
    }

    for (int i = 1; i <= barnCount; i++) {
        if (dists[i][0] >= dists[i][1]) canCatchAt[i] = true;
    }

    int farmersNeeded = 0;
    q.push(State{start, -1, -1});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (visited[cur.node]) continue;
        visited[cur.node] = true;
        bool k = true;
        if (canCatchAt[cur.node]) {
            for (int i = 0; i < connections[cur.node].size(); i++) {
                if (!canCatchAt[connections[cur.node][i]]) {
                    farmersNeeded++;
                    k = false;
                    break;
                }
            }
        }
        if (!k) continue;
        for (int i = 0; i < connections[cur.node].size(); i++) {
            q.push(State{connections[cur.node][i], -1, -1});
        }
    }
    cout << farmersNeeded << endl;
    return 0;
}
