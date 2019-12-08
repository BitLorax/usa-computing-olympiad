//
// Created by willj on 10/28/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 100000
#define INF 2000000000000000L

using namespace std;

long long order[MAX_N + 1][2];
long long loc[MAX_N + 1][2];
long long to[MAX_N + 1];
long long temp[MAX_N + 1];

namespace fenwicks {
    long long n;
    long long fenwick[MAX_N + 10];
    void update(long long index, long long add) {
        for (++index; index <= n; index += index&-index)
            fenwick[index] += add;
    }
    long long query(long long index) {
        long long ans = 0;
        for (++index; index > 0; index -= index&-index)
            ans += fenwick[index];
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("mincross.in");
    ofstream cout("mincross.out");

    long long n; cin >> n;
    for (long long j = 0; j < 2; j++) {
        for (long long i = 0; i < n; i++) {
            long long a; cin >> a; a--;
            loc[a][j] = i;
            order[i][j] = a;
            if (j) to[loc[a][0]] = i;
        }
    }
    long long sum, minSum = INF;
    fenwicks::n = n + 1;
    for (long long j = 0; j < 2; j++) {
        sum = 0;
        for (long long i = 0; i <= n; i++) fenwicks::fenwick[i] = 0;
        for (long long i = 0; i < n; i++) {
            sum += fenwicks::query(n + 1) - fenwicks::query(to[i]);
            fenwicks::update(to[i], 1);
        }
        for (long long i = n - 1; i >= 0; i--) {
            sum -= (n - 1 - loc[order[i][j]][(j + 1) % 2]);
            sum += (loc[order[i][j]][(j + 1) % 2] - 0);
            minSum = min(minSum, sum);
        }
        for (long long i = 0; i < n; i++) {
            temp[to[i]] = i;
        }
        for (long long i = 0; i < n; i++) {
            to[i] = temp[i];
        }
    }
    cout << minSum << endl;
    return 0;
}
