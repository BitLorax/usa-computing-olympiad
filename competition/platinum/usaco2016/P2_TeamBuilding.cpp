//
// Created by WillJ on 8/21/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_COWCNT 1000
#define MOD 1000000009

using namespace std;

long long fj[MAX_COWCNT + 1];
long long fp[MAX_COWCNT + 1];
long long DP[MAX_COWCNT + 1][MAX_COWCNT + 1][2]; //dp[n][m][k] = ways to win using n fj cows and m fp cows

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("team.in");
    ofstream cout("team.out");

    long long n, m, teamSize; cin >> n >> m >> teamSize;
    for (long long i = 0; i < n; i++) {
        cin >> fj[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> fp[i];
    }
    sort(fj, fj + n);
    sort(fp, fp + m);

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            DP[i][j][0] = 1;
        }
    }
    for (long long k = 1; k <= teamSize; k++) {
        for (long long i = 0; i <= n; i++) {
            for (long long j = 0; j <= m; j++) {
                DP[i][j][k % 2] = 0;
            }
        }
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                if (fj[i] > fp[j]) DP[i + 1][j + 1][k % 2] += DP[i][j][(k - 1) % 2];
            }
        }
        for (long long i = 0; i <= n; i++) {
            for (long long j = 0; j <= m; j++) {
                if (i > 0) DP[i][j][k % 2] += DP[i - 1][j][k % 2];
                if (j > 0) DP[i][j][k % 2] += DP[i][j - 1][k % 2];
                if (i > 0 && j > 0) DP[i][j][k % 2] -= DP[i - 1][j - 1][k % 2];
                DP[i][j][k % 2] = (DP[i][j][k % 2] % MOD + MOD) % MOD;
            }
        }
    }

    cout << DP[n][m][teamSize % 2] << endl;
    return 0;
}
