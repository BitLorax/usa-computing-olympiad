
#include <bits/stdc++.h>

#define N 200000
#define LOG 20
#define f first
#define s second

using namespace std;

vector<long long> c[N + 1];
long long cc[N + 1][3];
long long tops[N + 1];
map<pair<long long, long long>, long long> forks;
long long pSum[N + 1];

namespace lca {
    long long depth[N + 1];
    long long up[N + 1][LOG + 1];
    pair<long long, long long> pos[N + 1];

    long long counter = 0;

    void dfs(long long cur, long long par) {
        depth[cur] = depth[par] + 1;
        pos[cur].first = counter++;

        up[cur][0] = par;
        for (long long i = 1; i <= LOG; i++)
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        for (long long j : c[cur])
            if (j != par) dfs(j, cur);

        pos[cur].second = counter++;
    };
    bool isAncestor(long long a, long long b) {
        return pos[b].first >= pos[a].first && pos[b].second <= pos[a].second;
    }
    long long query(long long a, long long b) {
        if (isAncestor(a, b)) return a;
        if (isAncestor(b, a)) return b;
        for (long long i = LOG; i >= 0; i--)
            if (!isAncestor(up[a][i], b)) a = up[a][i];
        return up[a][0];
    }
}
long long top(long long bot, long long top) {
    if (bot == top) return 0;
    for (long long i = LOG; i >= 0; --i) {
        if (lca::depth[lca::up[bot][i]] > lca::depth[top]) bot = lca::up[bot][i];
    }
    return bot;
}
void calcSum(long long cur, long long par, long long sum) {
    pSum[cur] = sum;
    for (long long i : c[cur]) {
        if (i != par) calcSum(i, cur, sum + tops[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("exercise.in");
    ofstream cout("exercise.out");

    long long n, m; cin >> n >> m;
    for (long long i = 0; i < n - 1; ++i) {
        long long a, b; cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    lca::dfs(1, 1);

    long long res = 0;
    for (long long i = 0; i < (m - (n - 1)); ++i) {
        cin >> cc[i][0] >> cc[i][1];
        cc[i][2] = lca::query(cc[i][0], cc[i][1]);
        long long topA = top(cc[i][0], cc[i][2]), topB = top(cc[i][1], cc[i][2]);
        if (topA) {
            tops[topA]++;
            res -= tops[topA];
        }
        if (topB) {
            tops[topB]++;
            res -= tops[topB];
        }
        if (topA && topB) {
            res -= forks[make_pair(min(topA, topB), max(topA, topB))];
            forks[make_pair(min(topA, topB), max(topA, topB))]++;
        }
    }
    calcSum(1, 0, 0);
    for (long long i = 0; i < (m - (n - 1)); ++i) {
        res += pSum[cc[i][0]] + pSum[cc[i][1]] - 2 * pSum[cc[i][2]];
    }

    cout << res << endl;

    return 0;
}