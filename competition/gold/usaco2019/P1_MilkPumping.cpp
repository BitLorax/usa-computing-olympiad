
#include <bits/stdc++.h>

using namespace std;

struct Pipe {
    int to, cost, flow;
};

int n, m;
vector<Pipe> c[1010];
bool v[1010];
int res = 0;

void dfs(int at, int cost, int flow) {
    if (v[at]) return;
    if (cost != 0 && (int)(1000000 * (1.0 * flow / cost)) <= res) return;

    if (at == n) {
        res = max(res, (int)(1000000 * (1.0 * flow / cost)));
        return;
    }

    v[at] = true;
    for (Pipe to : c[at]) {
        dfs(to.to, cost + to.cost, min(flow, to.flow));
    }
    v[at] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("pump.in");
    ofstream cout("pump.out");
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost, f; cin >> a >> b >> cost >> f;
        c[a].push_back(Pipe{b, cost, f});
        c[b].push_back(Pipe{a, cost, f});
    }

    dfs(1, 0, 2000000000);
    cout << res << endl;

    return 0;
}