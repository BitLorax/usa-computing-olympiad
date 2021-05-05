//
// Created by WillJ on 12/26/2018.
//


#include <iostream>
#include <queue>

#define MAX_PIPECNT 99999

using namespace std;

int connections[MAX_PIPECNT + 1][2];
int dists[MAX_PIPECNT + 1];

int main() {
    int pipeCount, connectionCount; cin >> pipeCount >> connectionCount;
    for (int i = 0; i < connectionCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections[a][0] = b; connections[a][1] = c;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (dists[cur.first] != 0) continue;
        dists[cur.first] = cur.second;
        for (int i = 0; i < 2; i++) q.push(make_pair(connections[cur.first][i], cur.second + 1));
    }
    for (int i = 1; i <= pipeCount; i++) cout << dists[i] << endl;
    return 0;
}
