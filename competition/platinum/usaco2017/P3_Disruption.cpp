
#include <bits/stdc++.h>

#define N 50000
#define INF 2000000000
#define f first
#define s second

using namespace std;

struct Edge {
    int to, w, id;
    bool operator<(const Edge &a) const {
        return w < a.w;
    }
    bool operator==(const Edge &a) const {
        return id == a.id;
    }
};


vector<pair<int, int>> c[N + 1];
multiset<Edge> ms[N + 1];
int res[N + 1];

void dfs(int cur, int par) {
    for (auto i : c[cur]) {
        if (i.f == par) continue;
        dfs(i.f, cur);
        if (ms[i.f].size()) res[i.s] = min(res[i.s], ms[i.f].begin()->w);
        if (ms[cur].size() < ms[i.f].size()) swap(ms[cur], ms[i.f]);
        for (auto j : ms[i.f]) {
            if (ms[cur].find(j) != ms[cur].end()) ms[cur].erase(ms[cur].find(j));
            else ms[cur].insert(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("disrupt.in");
    ofstream cout("disrupt.out");

    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        c[a].emplace_back(b, i);
        c[b].emplace_back(a, i);
        res[i] = INF;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, w; cin >> a >> b >> w; a--; b--;
        ms[a].insert(Edge{b, w, i});
        ms[b].insert(Edge{a, w, i});
    }

    dfs(0, -1);

    for (int i = 0; i < n - 1; ++i) {
        if (res[i] == INF) res[i] = -1;
        cout << res[i] << endl;
    }
    
    return 0;
}