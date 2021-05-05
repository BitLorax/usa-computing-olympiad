//
// Created by willj on 10/10/2019.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 200
#define INF 2000000000

using namespace std;

vector<int> c[MAX_N + 1];
int v[MAX_N + 1][MAX_N + 1][2];

struct State {
    int pos, cPos, t;
    bool has;
};

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            v[i][j][0] = v[i][j][1] = INF;
        }
    }
    queue<State> q;
    q.push(State{0, n - 1, 0, false});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.t >= v[cur.pos][cur.cPos][cur.has]) continue;
        v[cur.pos][cur.cPos][cur.has] = cur.t;

        if (cur.pos == cur.cPos) continue;
        if (cur.has && cur.cPos == n - 1) continue;

        if (cur.pos == n - 1) cur.has = true;

        for (int i : c[cur.pos])
            q.push(State{i, (cur.cPos - 1 + n) % n, cur.t + 1, cur.has});
        q.push(State{cur.pos, (cur.cPos - 1 + n) % n, cur.t + 1, cur.has});
    }
    int t = INF;
    for (int i = 1; i < n; i++) t = min(v[0][i][1], t);
    cout << t << endl;
    return 0;
}
