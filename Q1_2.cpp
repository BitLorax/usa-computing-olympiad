
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

long long n;
bool a[2010][2010];
long long ps[2010][2010];
long long dp[2010][2010][2];

long long multi(long long a, long long b) {
    long long ret = 0;
    a %= MOD; b %= MOD;
    while (b > 0) {
        if (b % 2 == 1) ret = (ret + a) % MOD;
        a = (2 * a) % MOD;
        b /= 2;
    }
    return ret % MOD;
}
long long ctLeft(long long x, long long y) { // by index
    if (x < 0 || x >= n) return 0;
    return (x + 1) - ps[x + 1][y];
}
long long ctRight(long long x, long long y) {
    if (x < 0 || x >= n) return 0;
    return (n - x) - (ps[n][y] - ps[x][y]);
}
long long fastExpo(long long base, long long pow) {
    long long ret = 1, b = base;
    while (pow > 0) {
        if (pow % 2 == 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        pow /= 2;
    }
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream cin("sprinklers2.in");
    ofstream cout("sprinklers2.out");

    cin >> n;
    for (long long i = 0; i < n; ++i) {
        string s; cin >> s;
        for (long long j = 0; j < n; ++j) {
            a[j][i] = (s[j] == 'W');
            ps[j + 1][i] = ps[j][i] + a[j][i];
        }
        a[n][i] = 1;
    }
    for (long long x = 0; x <= n; ++x) {
        if (x > 0 && a[x - 1][0]) continue;
        dp[x][0][0] = fastExpo(2, ctLeft(x - 2, 0)) * fastExpo(2, ctRight(x + 1, 0));
        dp[x][0][1] = (a[x][0] ? 0 : dp[x][0][0]);
    }
    for (long long y = 1; y < n; ++y) {
        long long sum = 0;
        for (long long x = 0; x <= n; ++x) {
            if (x > 0 && !a[x - 1][y]) {
                // for (long long j = 0; j < x; ++j) {
                //     dp[x][y][0] = (dp[x][y][0] + multi(dp[j][y - 1][1], fastExpo(2, ctLeft(x - 2, y)))) % MOD;
                // }
                // for (long long j = 0; j < x; ++j) {
                //     dp[x][y][0] = (dp[x][y][0] + dp[j][y - 1][1]) % MOD;
                // }
                dp[x][y][0] = sum;
                dp[x][y][0] = multi(dp[x][y][0], fastExpo(2, ctLeft(x - 2, y)));
                // cout << x << " " << y << " " << dp[x][y][0] << " " << dpps[x] << endl;
                dp[x][y][0] = (dp[x][y][0] + multi(((dp[x][y - 1][0] + dp[x][y - 1][1]) % MOD), fastExpo(2, ctLeft(x - 1, y)))) % MOD;
            } else {
                dp[x][y][0] = (dp[x][y][0] + multi(((dp[x][y - 1][0] + dp[x][y - 1][1]) % MOD), fastExpo(2, ctLeft(x - 2, y)))) % MOD;
            }
            sum = (sum + dp[x][y - 1][1]) % MOD;
            dp[x][y][0] = multi(dp[x][y][0], fastExpo(2, ctRight(x + 1, y)));
            dp[x][y][1] = (a[x][y] ? 0 : dp[x][y][0]);
        }
    }
    // for (long long y = 0; y < n; ++y) {
    //     for (long long x = 0; x <= n; ++x) {
    //         cout << dp[x][y][0] << " ";
    //     }
    //     cout << endl;
    //     for (long long x = 0; x <= n; ++x) {
    //         cout << dp[x][y][1] << " ";
    //     }
    //     cout << endl;
    // }
    long long tot = 0;
    for (long long x = 0; x <= n; ++x) {
        tot = (tot + dp[x][n - 1][(x == n ? 0 : 1)] % MOD) % MOD;
    }
    cout << tot << endl;
    return 0;
}