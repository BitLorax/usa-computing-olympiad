//
// Created by willj on 11/9/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 1000
#define INF 2000000000
#define f first
#define s second

using namespace std;


pair<int, int> c[MAX_N * MAX_N + 1][2];
int b[MAX_N + 1][MAX_N + 1];
int ps[MAX_N + 1][MAX_N + 1];
bool valid[MAX_N * MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("art.in");
    ofstream cout("art.out");

    int n; cin >> n;
    for (int i = 0; i <= n * n; i++) {
        c[i][0].f = c[i][0].s = INF;
        c[i][1].f = c[i][1].s = -INF;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            valid[a] = true;
            b[j][i] = a;
            c[a][0].f = min(c[a][0].f, j);
            c[a][0].s = min(c[a][0].s, i);
            c[a][1].f = max(c[a][1].f, j);
            c[a][1].s = max(c[a][1].s, i);
        }
    }

    int sum = 0;
    for (int i = 1; i <= n * n; i++) {
        if (valid[i]) sum++;
    }
    if (sum == 1) {
        cout << n * n - 1 << endl;
        return 0;
    }

    for (int i = 1; i <= n * n; i++) {
        valid[i] = true;
        if (c[i][0].f == INF) continue;
        ps[c[i][0].f][c[i][0].s]++;
        ps[c[i][1].f + 1][c[i][1].s + 1]++;
        ps[c[i][0].f][c[i][1].s + 1]--;
        ps[c[i][1].f + 1][c[i][0].s]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ps[i][j] += (i ? ps[i - 1][j] : 0) + (j ? ps[i][j - 1] : 0) - (i && j ? ps[i - 1][j - 1] : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ps[i][j] > 1) valid[b[i][j]] = false;
        }
    }
    int tot = 0;
    for (int i = 1; i <= n * n; i++) {
        tot += valid[i];
    }

    cout << tot << endl;
    return 0;
}
