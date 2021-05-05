//
// Created by WillJ on 12/31/2018.
//

#include <iostream>
#include <queue>

#define INF 1000000000
#define MAX_FARMCNT 200

using namespace std;

struct State {
    long long node, len;
    bool passedHub;
    bool operator<(const State &a) const {
        return len > a.len;
    }
};

long long connections[MAX_FARMCNT + 1][MAX_FARMCNT + 1];
long long dists[MAX_FARMCNT + 1][MAX_FARMCNT + 1][2];

int main() {
    long long farmCount, flightCount, hubCount, queryCount; cin >> farmCount >> flightCount >> hubCount >> queryCount;
    for (long long i = 1; i <= farmCount; i++) {
        for (long long j = 1; j <= farmCount; j++) {
            connections[i][j] = INF;
            dists[i][j][0] = INF; dists[i][j][1] = INF;
        }
    }
    for (long long i = 0; i < flightCount; i++) {
        long long a, b, c; cin >> a >> b >> c;
        connections[a][b] = c;
    }

    for (long long i = 1; i <= farmCount; i++) {
        priority_queue<State> q;
        q.push(State{i, 0, (i <= hubCount)});
        while (!q.empty()) {
            State cur = q.top(); q.pop();
            if (dists[i][cur.node][cur.passedHub] != INF) continue;
            dists[i][cur.node][cur.passedHub] = cur.len;
            for (long long j = 1; j <= farmCount; j++) {
                if (connections[cur.node][j] != INF) {
                    q.push(State{j, cur.len + connections[cur.node][j], (j <= hubCount) || cur.passedHub});
                }
            }
        }
    }
    long long possible = 0, sum = 0;
    for (long long i = 0; i < queryCount; i++) {
        long long a, b; cin >> a >> b;
        if (dists[a][b][1] != INF) {
            possible++;
            sum += dists[a][b][1];
        }
    }
    cout << possible << endl;
    cout << sum << endl;
    return 0;
}
