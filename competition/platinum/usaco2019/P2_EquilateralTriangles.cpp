
#include <bits/stdc++.h>

#define N 300

using namespace std;

int n;
int a[N + 1][N + 1];
int t[N + 1][N + 1];

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            a[j][i] = (s[j] == '*');
        }
    }
    
    int tot = 0;
    for (int l = 0; l < 4; l++) {
        for (int r = 2; r <= 2 * n; r += 2) {
            for (int i = 0; i < 2 * n; ++i) {
                int ct = 0;
                int x = max(0, i - (n - 1)), y = min(i, n - 1);
                int rx = x, ry = y + r, lx = rx, ly = ry;
                for (int j = max(0, i - (n - 1)); j < min(i, n - 1) + 1; ++j) {
                    while (j == max(0, i - (n - 1)) && ry - r / 2 > y) {
                        if (valid(rx, ry) && valid(rx + r / 2, ry - r / 2))
                            ct += (a[rx][ry] && a[rx + r / 2][ry - r / 2]);
                        rx++; ry--;
                    }
                    if (a[x][y]) tot += ct;
                    
                    if (valid(lx, ly) && valid(lx + r / 2, ly - r / 2))
                        ct -= a[lx][ly] && a[lx + r / 2][ly - r / 2];
                    if (valid(rx, ry) && valid(rx + r / 2, ry - r / 2))
                        ct += a[rx][ry] && a[rx + r / 2][ry - r / 2];
                    x++; y--; lx++; ly--; rx++; ry--;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t[n - 1 - j][i] = a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = t[i][j];
            }
        }
    }

    cout << tot << endl;

    return 0;
}
