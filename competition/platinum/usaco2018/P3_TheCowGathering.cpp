
#include <bits/stdc++.h>

#define N 100000

using namespace std;

vector<int> c[N + 1];
vector<int> cc[N + 1];
int neigh[N + 1];
int after[N + 1];
int before[N + 1];
bool v[N + 1];
bool res[N + 1];

vector<int> q;

void dfs(int cur, int par = -1) {
    if (before[cur] > 0) return;
    res[cur] = true;
    for (int to : c[cur]) {
        if (to != par) dfs(to, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("gathering.in");
    ofstream cout("gathering.out");
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        c[a].push_back(b);
        c[b].push_back(a);
        neigh[a]++; neigh[b]++;
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        cc[a].push_back(b);
        after[b]++; before[a]++;
    }
    for (int i = 0; i < n; ++i) {
        if (neigh[i] == 1 && after[i] == 0) {
            q.push_back(i);
            v[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i >= q.size()) {
            for (int j = 0; j < n; ++j) {
                cout << "0" << endl;
            }
            return 0;
        }
        for (int to : c[q[i]]) {
            neigh[to]--;
            if (!v[to] && neigh[to] <= 1 && after[to] == 0) {
                q.push_back(to);
                v[to] = true;
            }
        }
        for (int to : cc[q[i]]) {
            after[to]--;
            if (!v[to] && neigh[to] <= 1 && after[to] == 0) {
                q.push_back(to);
                v[to] = true;
            }
        }
    }
    res[q[n - 1]] = true;
    dfs(q[n - 1]);

    for (int i = 0; i < n; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}