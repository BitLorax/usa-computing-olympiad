//
// Created by willj on 11/9/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 100000
#define MAX_K 110
#define INF 2000000000000LL

using namespace std;

struct Seg {
    long long lo, hi;
};

bool compA(const Seg &a, const Seg &b) {
    if (a.lo == b.lo) return a.hi > b.hi;
    return a.lo < b.lo;
}
bool compB(const Seg &a, const Seg &b) {
    if (a.lo == b.lo) return a.hi < b.hi;
    return a.lo < b.lo;
}

Seg a[MAX_N + 1];
long long dp[MAX_N + 1][MAX_K + 1];
long long best[MAX_K + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");

    long long n, k; cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> a[i].lo >> a[i].hi;
    }
    sort(a, a + n, compA);
    long long end = -1, indx = 0;
    long long N = n;
    for (long long i = 0; i < N; i++) {
        if (a[i].hi <= end) {
            k--; n--;
        } else {
            a[indx++] = a[i];
            end = a[i].hi;
        }
    }

    sort(a, a + n, compB);
    long long l = 0;
    for (long long i = 0; i < n; i++) {
        while (a[l].hi < a[i].lo) {
            for (long long j = 100; j >= 0; j--) {
                best[j] = max(best[j], max(best[j + 1], max(best[j - 1], dp[l][j])));
            }
            l++;
        }
        for (long long j = 0; j <= 100; j++) {
            if (j <= (i + 1) - 1) {
                long long len = a[i].hi - a[i].lo;
                dp[i][j] = len;
                dp[i][j] = max(dp[i][j], dp[l][max(0LL, j - (i - l - 1))] + len - (a[l].hi - a[i].lo));
                dp[i][j] = max(dp[i][j], best[max(0LL, j - (i - l))] + len);
            }
            else dp[i][j] = -INF;
            dp[i][j] = dp[i][j];
        }
    }
    long long res = 0;
    for (long long i = 0; i < n; i++) {
        if (k - (n - (i + 1)) >= 0) {
            res = max(res, dp[i][k - (n - (i + 1))]);
        }
    }
    cout << res << endl;
    return 0;
}
