
#include <bits/stdc++.h>

#define MAX_S 1000
#define MOD 1000000007

using namespace std;

bool a[MAX_S + 1][MAX_S + 1];
int up[MAX_S + 1][MAX_S + 1];
int id[MAX_S + 1][MAX_S + 1];
vector<int> c[MAX_S * MAX_S + 1];

long long ct[MAX_S * MAX_S + 1];

namespace uf {
    int n, m;
    int comp[MAX_S + 1][MAX_S + 1];
    void construct(int a, int b) {
        n = a; m = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                comp[j][i] = j;
            }
        }
    }
    int find(int layer, int node) {
        if (comp[node][layer] != node) return comp[node][layer] = find(layer, comp[node][layer]);
        return node;
    }
    void join(int layer, int a, int b) {
        comp[uf::find(layer, a)][layer] = uf::find(layer, b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cave.in");
    ofstream cout("cave.out");

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            a[j][i] = (s[j] == '#');
        }
    }

    uf::construct(n, m);
    memset(up, -1, sizeof up);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m - 1; ++j) {
            if (!a[j][i] && !a[j + 1][i]) {
                uf::join(i, j, j + 1);
            }
        }
        if (i == n - 1) continue;
        for (int j = 0; j < m; ++j) {
            if (a[j][i] || a[j][i + 1]) continue;
            if (up[i + 1][uf::find(i + 1, j)] == -1) {
                up[i + 1][uf::find(i + 1, j)] = j;
            }
            else {
                uf::join(i, j, up[i + 1][uf::find(i + 1, j)]);
            }
        }
    }

    int t = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (!a[j][i] && uf::find(i, j) == j) {
                id[j][i] = t++;
            }
        }
    }
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (!(!a[j][i] && uf::find(i, j) == j)) continue;
            if (up[i][j] != -1) c[id[uf::find(i - 1, up[i][j])][i - 1]].push_back(id[j][i]);
            else c[t].push_back(id[j][i]);
        }
    }

    for (int i = 0; i <= t; ++i) {
        ct[i] = 1;
        for (auto j : c[i]) {
            ct[i] = (ct[i] * ct[j]) % MOD;
        }
        ct[i]++;
    }
    
    cout << (ct[t] - 1 + MOD) % MOD << endl;

    return 0;
}