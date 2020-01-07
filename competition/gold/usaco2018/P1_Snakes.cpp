
#include <bits/stdc++.h>

#define MAX_N 400
#define MAX_K 400
#define LOG 20
#define INF 2000000000

using namespace std;

long long a[MAX_N + 1];
long long pSum[MAX_N + 1];
long long dp[MAX_N + 1][MAX_K + 1];

namespace rmq {
    long long n;
    long long maxs[MAX_N + 1][LOG + 1];
    void preprocess(long long size) {
        n = size;

        for (long long i = 0; i < n; i++) maxs[i][0] = i;
        for (long long j = 1; (1 << j) <= n; j++) {
            for (long long i = 0; (i + (1 << j)) <= n; i++) {
                if (a[maxs[i][j - 1]] > a[maxs[i + (1 << (j - 1))][j - 1]]) maxs[i][j] = maxs[i][j - 1];
                else maxs[i][j] = maxs[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    long long query(long long lo, long long hi) {
        long long i = (long long)(log2(hi - lo + 1));
        if (a[maxs[lo][i]] >= a[maxs[hi - (1 << i) + 1][i]]) return maxs[lo][i];
        return maxs[hi - (1 << i) + 1][i];
    }
};


long long query(long long lo, long long hi) {
	return (hi - lo + 1) * a[rmq::query(lo, hi)] - (pSum[hi + 1] - pSum[lo]);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("snakes.in");
    ofstream cout("snakes.out");
    
    long long n, k; cin >> n >> k; k++;

    for (long long i = 0; i < n; ++i) {
    	cin >> a[i];
    	pSum[i + 1] = pSum[i] + a[i];
    }
    for (long long i = 0; i <= n; i++) {
    	for (long long j = 0; j <= k; ++j) {
    		dp[i][j] = INF;
    	}
    }

    rmq::preprocess(n);

    dp[0][0] = 0;
    for (long long i = 1; i <= n; i++) {
    	for (long long j = 1; j <= k; j++) {
    		for (long long l = 0; l < i; l++) {
    			dp[i][j] = min(dp[i][j], dp[l][j - 1] + query(l, i - 1));
    		}
    	}
    }

    cout << dp[n][k] << endl;

    return 0;
}