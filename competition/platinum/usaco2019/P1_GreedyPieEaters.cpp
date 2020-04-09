
#include <bits/stdc++.h>

#define N 300

using namespace std;

long long best[N + 1][N + 1][N + 1];
long long dp[N + 1][N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("pieaters.in");
    ofstream cout("pieaters.out");
    
    long long n, m; cin >> n >> m;
    for (long long i = 0; i < m; ++i) {
        long long w, l, r; cin >> w >> l >> r; l--; r--;
        for (long long j = l; j <= r; ++j) {
            best[j][l][r] = max(best[j][l][r], w);
        }
    }
    for (long long i = 0; i < n; ++i) {
        for (long long lo = i; lo >= 0; --lo) {
            for (long long hi = i; hi < n; ++hi) {
                if (lo) best[i][lo - 1][hi] = max(best[i][lo - 1][hi], best[i][lo][hi]);
                if (hi < n - 1) best[i][lo][hi + 1] = max(best[i][lo][hi + 1], best[i][lo][hi]);
            }
        }
    }
    for (long long i = n - 1; i >= 0; --i) {
        for (long long j = i; j < n; ++j) {
            for (long long k = i; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for (long long k = i; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], (k == i ? 0 : dp[i][k - 1]) + (k == j ? 0 : dp[k + 1][j]) + best[k][i][j]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}