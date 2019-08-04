//
// Created by WillJ on 2/23/2019.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
#define MAX_PASTURECNT 50000
#define MAX_BALECNT 50000

using namespace std;

struct Path {
    int target, len;
};
struct Bale {
    int node, benefit;
};

vector<Path> connections[MAX_PASTURECNT + 1];
vector<Bale> bales;
int minDists[MAX_PASTURECNT + 1];
int minDistsWithBale[MAX_PASTURECNT + 1];

int main() {

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    int pastureCount, pathCount, baleCount; cin >> pastureCount >> pathCount >> baleCount;
    for (int i = 0; i < pathCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections[a].push_back(Path{b, c});
        connections[b].push_back(Path{a, c});
    }
    for (int i = 0; i < baleCount; i++) {
        int a, b; cin >> a >> b;
        bales.push_back(Bale{a, b});
    }

    for (int i = 0; i <= pastureCount; i++) {
        minDistsWithBale[i] = -1;
        minDists[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //<len, node>
    q.push(make_pair(0, pastureCount));
    while (!q.empty()) {
        pair<int, int> cur = q.top(); q.pop();
        if (minDists[cur.second] != -1) continue;
        minDists[cur.second] = cur.first;
        for (Path i : connections[cur.second]) {
            q.push(make_pair(cur.first + i.len, i.target));
        }
    }

    for (int i = 0; i < baleCount; i++) {
        q.push(make_pair(-1 * bales[i].benefit + minDists[bales[i].node], bales[i].node));
    }
    while (!q.empty()) {
        pair<int, int> cur = q.top(); q.pop();
        if (minDistsWithBale[cur.second] != -1) continue;
        minDistsWithBale[cur.second] = cur.first;
        for (Path i : connections[cur.second]) {
            q.push(make_pair(cur.first + i.len, i.target));
        }
    }

    for (int i = 1; i < pastureCount; i++) {
        cout << (minDistsWithBale[i] <= minDists[i]) << endl;
    }
    return 0;
}
