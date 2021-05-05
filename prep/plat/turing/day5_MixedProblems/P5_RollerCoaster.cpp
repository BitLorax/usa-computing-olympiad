//
// Created by willj on 11/24/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 1000
#define MAX_L 300000
#define f first
#define s second

using namespace std;

int f[MAX_N + 1];
int d[MAX_N + 1];
int dp[MAX_L + 1];
int tdp[MAX_L + 1];


int main() {
    int n, k, l; cin >> n >> k >> l;
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> d[i];
    }
    for (int j = 1; j <= l; j++) {
        dp[j] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = l; j >= 0; j--) {
            if (dp[j] == -1) continue;
            if (j + d[i] <= l) dp[j + d[i]] = max(dp[j + d[i]], dp[j] + f[i]);
            tdp[max(0, j - k)] = max(tdp[max(0, j - k)], dp[j]);
        }
        for (int j = 0; j <= l; j++) {
            dp[j] = max(dp[j], tdp[j]);
            tdp[j] = 0;
        }
    }

    int res = 0;
    for (int j = 0; j <= l; j++) {
        res = max(res, dp[j]);
    }
    cout << res << endl;
    return 0;
}
