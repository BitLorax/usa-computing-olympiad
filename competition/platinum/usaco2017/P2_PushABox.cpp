//
// Created by willj on 11/29/2019.
//

#include <bits/stdc++.h>

#define MAX_S 1500
#define f first
#define s second

using namespace std;

struct State {
    int x, y, direc; //{r, l, d, u}
};

int n, m, q;
bool a[MAX_S + 1][MAX_S + 1];
bool vv[MAX_S + 1][MAX_S + 1][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(pair<int, int> u) {
    if (u.f < 0 || u.f >= m || u.s < 0 || u.s >= n) return false;
    if (a[u.f][u.s]) return false;
    return true;
}

namespace bcc {
    stack<pair<pair<int, int>, pair<int,int>>> s; //<bot, top>
    int in[MAX_S + 1][MAX_S + 1], lo[MAX_S + 1][MAX_S + 1], t = 0, count = 0;
    vector<int> bcc[MAX_S + 1][MAX_S + 1];
    bool v[MAX_S + 1][MAX_S + 1];

    bool biconnected(pair<int, int> a, pair<int, int> b) {
        for (int j : bcc[a.f][a.s]) {
            if (binary_search(bcc[b.f][b.s].begin(), bcc[b.f][b.s].end(), j)) return true;
        }
        return false;
    }
    void dfs(pair<int, int> cur, pair<int, int> par = make_pair(-1, -1)) {
        lo[cur.f][cur.s] = in[cur.f][cur.s] = ++t;
        v[cur.f][cur.s] = true;
        for (int k = 0; k < 4; k++) {
            pair<int, int> to = make_pair(cur.f + dx[k], cur.s + dy[k]);
            if (!valid(to)) continue;
            if (to == par) continue;
            if (!v[to.f][to.s]) {
                s.emplace(to, cur);
                dfs(to, cur);
                lo[cur.f][cur.s] = min(lo[cur.f][cur.s], lo[to.f][to.s]);
                if (lo[to.f][to.s] >= in[cur.f][cur.s]) {
                    while (1) {
                        auto p = s.top(); s.pop();
                        pair<int, int> a = p.f, b = p.s;
                        if (bcc[a.f][a.s].empty() || bcc[a.f][a.s].back() != count) bcc[a.f][a.s].push_back(count);
                        if (bcc[b.f][b.s].empty() || bcc[b.f][b.s].back() != count) bcc[b.f][b.s].push_back(count);
                        if (a == to && b == cur) break;
                    }
                    count++;
                }
            } else if (in[to.f][to.s] < in[cur.f][cur.s]) {
                s.emplace(to, cur);
                lo[cur.f][cur.s] = min(lo[cur.f][cur.s], in[to.f][to.s]);
            }
        }
    }
    void run() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!v[i][j]) dfs(make_pair(i, j));
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("pushabox.in");
    ofstream cout("pushabox.out");

    cin >> n >> m >> q;
    pair<int, int> start, box;
    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        for (int j = 0; j < m; j++) {
            a[j][i] = (row[j] == '#');
            if (row[j] == 'A') start = make_pair(j, i);
            if (row[j] == 'B') box = make_pair(j, i);
        }
    }

    bcc::run();

    queue<pair<int, int>> qu; qu.push(make_pair(start.f, start.s));
    queue<State> quu;
    bool done = false;
    while (!qu.empty() && !done) {
        pair<int, int> cur = qu.front(); qu.pop();
        if (!valid(cur)) continue;
        if (vv[cur.f][cur.s][4]) continue;
        vv[cur.f][cur.s][4] = true;

        for (int k = 0; k < 4; k++) {
            if (cur.f + -dx[k] == box.f && cur.s + -dy[k] == box.s) {
                quu.push(State{box.f, box.s, k});
                done = true;
                break;
            }
            qu.push({cur.f + dx[k], cur.s + dy[k]});
        }
    }

    while (!quu.empty()) {
        State cur = quu.front(); quu.pop();
        if (cur.x < 0 || cur.x >= m || cur.y < 0 || cur.y >= n) continue;
        if (vv[cur.x][cur.y][cur.direc] || a[cur.x][cur.y]) continue;
        vv[cur.x][cur.y][cur.direc] = true;

        int nx = cur.x + -dx[cur.direc], ny = cur.y + -dy[cur.direc];
        if (valid({nx, ny})) {
            if (!a[nx][ny])
                quu.push(State{nx, ny, cur.direc});
        }

        for (int k = 0; k < 4; k++) {
            if (k == cur.direc) continue;
            nx = cur.x + dx[k]; ny = cur.y + dy[k];
            if (!valid({nx, ny})) continue;
            if (bcc::biconnected(make_pair(cur.x + dx[cur.direc], cur.y + dy[cur.direc]), make_pair(nx, ny)))
                quu.push(State{cur.x, cur.y, k});
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y; cin >> y >> x; x--; y--;
        if (vv[x][y][0] || vv[x][y][1] || vv[x][y][2] || vv[x][y][3] || (x == box.f && y == box.s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
