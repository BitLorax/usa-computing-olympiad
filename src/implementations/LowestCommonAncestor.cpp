
#include <iostream>
#include <vector>
#include <cmath>

#define N 1000
#define LOG 12

using namespace std;

vector<int> connections[N + 1];

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
        for (int j : connections[cur])
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
};
