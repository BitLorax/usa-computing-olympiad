//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define INF 2000000000
#define MAX_FIELDCNT 100000

using namespace std;

int color[MAX_FIELDCNT + 1];

struct Neighbor {
    int a;
    bool operator<(const Neighbor &b) const {
        return color[a] < color[b.a];
    }
};

vector<int> connections[MAX_FIELDCNT + 1];
vector<Neighbor> extended[MAX_FIELDCNT + 1];
bool visited[MAX_FIELDCNT + 1];

struct State {
    int node, par, parpar;
};

int main() {
//
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);

    int fieldCount; cin >> fieldCount;
    for (int i = 0; i < fieldCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for (int i = 1; i <= fieldCount; i++) color[i] = INF;
    queue<State> q;
    q.push(State{1, -1, -1});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (visited[cur.node]) continue;
        visited[cur.node] = true;
        if (cur.par != -1) {
            extended[cur.node].push_back(Neighbor{cur.par});
            extended[cur.par].push_back(Neighbor{cur.node});
        }
        if (cur.parpar != -1) {
            extended[cur.node].push_back(Neighbor{cur.parpar});
            extended[cur.parpar].push_back(Neighbor{cur.node});
        }
        for (int i : connections[cur.node]) {
            for (int j : connections[cur.node]) {
                if (i != j) extended[i].push_back(Neighbor{j});
            }
            q.push(State{i, cur.node, cur.par});
        }
    }

    for (int i = 0; i <= fieldCount; i++) visited[i] = false;

    queue<int> qq;
    int maxColor = 0;
    qq.push(1);
    while (!qq.empty()) {
        int i = qq.front(); qq.pop();
        if (visited[i]) continue;
        visited[i] = true;
        int potentialColor = 1;
        sort(extended[i].begin(), extended[i].end());
        for (Neighbor j : extended[i]) {
            if (j.a == potentialColor) potentialColor++;
            if (potentialColor < j.a) break;
        }
        color[i] = potentialColor;
        maxColor = max(maxColor, color[i]);
        for (int j : connections[i]) {
            qq.push(j);
        }
    }
    cout << maxColor << endl;
    return 0;
}