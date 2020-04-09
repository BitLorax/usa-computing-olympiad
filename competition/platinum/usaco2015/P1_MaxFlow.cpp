//
// Created by WillJ on 8/14/2019.
//

#include <iostream>
#include <vector>
#include <fstream>

#define MAX_STALLCNT 50000
#define LOG 17

using namespace std;

vector<int> connections[MAX_STALLCNT + 1];
int change[MAX_STALLCNT + 1];
int maxPumped = 0;

namespace lca {
    int depth[MAX_STALLCNT + 1];
    int up[MAX_STALLCNT + 1][LOG + 1];
    pair<int, int> pos[MAX_STALLCNT + 1];

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
}

int dfs(int cur, int par = 0) {
    int sum = 0;
    for (int i : connections[cur]) {
        if (i == par) continue;
        sum += dfs(i, cur);
    }
    sum += change[cur];
    maxPumped = max(maxPumped, sum);
    return sum;
}

int main() {

    ifstream cin("src/competition/test.in");
    ofstream cout("src/competition/test.out");

    int stallCount, pairCount; cin >> stallCount >> pairCount;
    for (int i = 0; i < stallCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    lca::dfs(1, 1);
    for (int i = 0; i < pairCount; i++) {
        int a, b; cin >> a >> b;
        int c = lca::query(a, b);
        if (lca::up[c][0] != c) change[lca::up[c][0]] --;
        change[c]--;
        change[a]++; change[b]++;
    }
    dfs(1);

    cout << maxPumped << endl;
    return 0;
}
