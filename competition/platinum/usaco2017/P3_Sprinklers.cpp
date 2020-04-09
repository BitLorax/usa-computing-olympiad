//
// Created by willj on 11/24/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 100000
#define MOD 1000000007
#define INF 2000000000

using namespace std;

long long a[MAX_N + 1];
long long lo[MAX_N + 1];
long long hi[MAX_N + 1];

long long b[MAX_N + 1];
long long pSum[MAX_N + 1];
long long ppSum[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("sprinklers.in");
    ofstream cout("sprinklers.out");

    long long n; cin >> n;
    for (long long i = 0; i < n; i++) {
        long long u; cin >> u;
        cin >> a[u];
    }
    long long y = n - 1;
    for (long long i = 0; i < n; i++) {
        while (a[i] <= y) b[y--] = i;
    }
    for (long long i = n - 1; i >= 0; i--) {
        pSum[i] = (pSum[i + 1] + b[i] + MOD) % MOD;
    }
    for (long long i = n - 1; i >= 0; i--) {
        ppSum[i] = (ppSum[i + 1] + (b[i] * (n - i) + MOD) % MOD + MOD) % MOD;
    }
    for (long long i = n - 1; i >= 0; i--) {
        hi[i] = max(a[i], hi[i + 1]);
    }
    for (long long i = 0; i < n; i++) {
        lo[i] = min(a[i], (i ? lo[i - 1] : INF));
    }

    long long res = 0;
    for (long long x = 1; x < n; x++) {
        long long len = hi[x] - lo[x];
        long long tot = (((len * (len + 1) / 2 + MOD) % MOD) * x + MOD) % MOD;
        long long u = (((ppSum[lo[x]] - ppSum[hi[x]] + MOD) % MOD) - (((pSum[lo[x]] - pSum[hi[x]] + MOD) % MOD) * (n - hi[x])) % MOD + MOD) % MOD;
        res = (res % MOD + ((tot - u + MOD) % MOD)) % MOD;
    }

    cout << res << endl;
    return 0;
}
