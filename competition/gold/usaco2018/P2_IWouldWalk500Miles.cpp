

#include <bits/stdc++.h>

#define N 7500
#define X 2019201913
#define Y 2019201949
#define MOD 2019201997

using namespace std;

bool v[N + 1];
int d[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("test.in");
    ofstream cout("test.out");
    
    int n, k; cin >> n >> k;

    for (int ii = 0; ii < N; ++ii) {
        int to = 1;
        for (int i = 1; i <= N; ++i) {
            if (!v[i] && d[i] < d[to]) to = i;
        }
        v[to] = true;
        for (int i = 1; i <= n; i++) {
        	if (!v[i]) d[i] = min(d[i], (X * min(to, i) + Y * max(to, i)) % MOD);
        }
    }

    sort(d + 1, d + n + 1);

    cout << d[n - k + 1] << endl;

    return 0;
}