
#include <bits/stdc++.h>
#include "grader.h"

#define N 100000
#define LOG 20

using namespace std;

vector<int> c[N + 1];
int s[N + 1], x[N + 1], y[N + 1];

namespace lca {
    int depth[N + 1];
    int up[N + 1][LOG + 1];
    pair<int, int> pos[N + 1];

    int counter = 0;

    void dfs(int cur, int par) {
        depth[cur] = depth[par] + 1;
        pos[cur].first = counter++;

        up[cur][0] = par;
        for (int i = 1; i <= LOG; i++)
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
        for (int i = LOG; i >= 0; i--)
            if (!isAncestor(up[a][i], b)) a = up[a][i];
        return up[a][0];
    }
}

//placeholder
// int getN() { return 3; }
// void setFarmLocation(int a, int b, int c) {
//     cout << a << " " << b << " " << c << endl;
//     return;
// }
// void addBox(int a, int b, int c, int d) {
//     cout << a << " " << b << " " << c << " " << d << endl;
//     return;
// }

void calcSize(int cur, int par) {
    s[cur] = 1;
    for (auto i : c[cur]) {
        if (i != par) {
            calcSize(i, cur);
            s[cur] += s[i];
        }
    }
}
void place(int cur, int par, int xlo, int xhi, int ylo, int yhi) {
    x[cur] = xlo++; y[cur] = ylo++;
    setFarmLocation(cur, x[cur], y[cur]);
    for (auto i : c[cur]) {
        if (i == par) continue;
        place(i, cur, xhi - (s[i] - 1), xhi, ylo, ylo + (s[i] - 1));
        xhi -= s[i]; ylo += s[i];
    }
}

void addRoad(int a, int b) {
    c[a].push_back(b);
    c[b].push_back(a);
}
void buildFarms() {
    int n = getN();
    lca::dfs(0, 0);
    calcSize(0, -1);
    place(0, -1, 1, n, 1, n);
}
void notifyFJ(int a, int b) {
    int c = lca::query(a, b);
    addBox(min(x[a], x[c]), min(y[a], y[c]), max(x[a], x[c]), max(y[a], y[c]));
    if (c != b) {
        int child = b;
        for (int i = LOG; i >= 0; --i) {
            if (lca::depth[lca::up[child][i]] > lca::depth[c]) child = lca::up[child][i];
        }
        addBox(min(x[b], x[child]), min(y[b], y[child]), max(x[b], x[child]), max(y[b], y[child]));
    }
}