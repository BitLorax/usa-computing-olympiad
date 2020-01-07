
#include <bits/stdc++.h>

using namespace std;

long long d[30][30];
long long a[100010];
long long dd[100010][30];
long long dp[100010];
long long minVal[30];

long long change(long long i, long long j, long long c) {
    return dd[j][c] - (i ? dd[i - 1][c] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cowmbat.in");
    ofstream cout("cowmbat.out");
    
    long long n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    for (long long i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
    }
    for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < m; ++j) {
            cin >> d[i][j];
        }
    }

    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 0; j < m; ++j) {
            dd[i][j] = d[a[i - 1]][j] + dd[i - 1][j];
        }
    }

    for (long long i = 0; i <= n; ++i) {
        dp[i] = 2000000000;
    }

    for (long long i = k; i <= n; ++i) {
        long long minChar = -1;
        for (long long c = 0; c < m; ++c) {
            long long j = i - k;
            minVal[c] = min(minVal[c], dp[j] - dd[j][c]);
            dp[i] = min(dp[i], minVal[c] + dd[i][c]);
            if (dp[i] == minVal[c] + dd[i][c]) {
                minChar = c;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}