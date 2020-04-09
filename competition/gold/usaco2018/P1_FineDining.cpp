
#include <bits/stdc++.h>

#define MAX_N 50000
#define INF 2000000000
#define f first
#define s second

using namespace std;

struct State {
    int at, len;
    bool operator<(const State &a) const {
        return len > a.len;
    }
};


vector<pair<int, int>> c[MAX_N + 1];
int dist1[MAX_N + 1], dist2[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("dining.in");
    ofstream cout("dining.out");

    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        c[a].emplace_back(b, w);
        c[b].emplace_back(a, w);
    }

    for (int i = 0; i <= n; i++) dist1[i] = dist2[i] = INF;

    priority_queue<State> pq; pq.push(State{n, 0});
    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        if (dist1[cur.at] != INF) continue;
        dist1[cur.at] = cur.len;
        for (pair<int, int> to : c[cur.at]) pq.push(State{to.f, cur.len + to.s});
    }
    priority_queue<State> temp; swap(pq, temp);

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        c[0].emplace_back(a, dist1[a] - b);
    }

    pq.push(State{0, 0});
    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        if (dist2[cur.at] != INF) continue;
        dist2[cur.at] = cur.len;
        for (pair<int, int> to : c[cur.at]) pq.push(State{to.f, cur.len + to.s});
    }

    for (int i = 1; i < n; i++) {
        cout << (dist2[i] <= dist1[i]) << endl;
    }
    return 0;
}