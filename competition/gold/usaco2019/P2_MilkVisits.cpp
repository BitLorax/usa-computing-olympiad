
#include <bits/stdc++.h>

#define N 100000

using namespace std;

int C = 0;
int t[100010];
vector<int> c[100010];

vector<int> want[100010];
map<int, int> has[100010];
int curHas[100010];
struct Query {
    int a, b, k, targ;
};

Query q[100010];

namespace lca {
    int depth[N + 1];
    int up[N + 1][20 + 1];
    pair<int, int> pos[N + 1];

    int counter = 0;

    void dfs(int cur, int par) {
        depth[cur] = depth[par] + 1;
        pos[cur].first = counter++;

        up[cur][0] = par;
        for (int i = 1; i <= 20; i++)
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        for (int j : c[cur])
            if (j != par) dfs(j, cur);

        pos[cur].second = counter++;
    };
    bool isAncestor(int a, int b) {
        return pos[b].first >= pos[a].first && pos[b].second <= pos[a].second;
    }
    int query(int a, int b) {
        if (isAncestor(a, b)) return a;
        if (isAncestor(b, a)) return b;
        for (int i = 20; i >= 0; i--)
            if (!isAncestor(up[a][i], b)) a = up[a][i];
        return up[a][0];
    }
}

int dfs(int at, int par) {
    curHas[t[at]]++;
    for (int i : want[at]) {
        has[at].insert(make_pair(i, curHas[i]));
    }
    for (int to : c[at]) {
        if (to != par) dfs(to, at);
    }
    curHas[t[at]]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        C = max(C, t[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    c[0].push_back(1);

    lca::dfs(1, 1);

    for (int i = 0; i < m; ++i) {
        cin >> q[i].a >> q[i].b >> q[i].targ;
        int k = lca::query(q[i].a, q[i].b);
        q[i].k = k;
        want[q[i].a].push_back(q[i].targ);
        want[q[i].b].push_back(q[i].targ);
        want[k].push_back(q[i].targ);
    }

    dfs(1, 1);

    for (int i = 0; i < m; ++i) {
        Query cur = q[i];
        if ((has[cur.a][cur.targ] + has[cur.b][cur.targ] - 2 * has[cur.k][cur.targ]) > 0 || t[cur.k] == cur.targ) cout << "1";
        else cout << "0";
    }

    cout << endl;

    return 0;
}