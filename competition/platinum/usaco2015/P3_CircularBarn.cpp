//
// Created by willj on 9/19/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define INF 2000000000000000000
#define f first
#define s second
#define MAX_ROOMCNT 1000
#define MAX_ENTRYCNT 7

using namespace std;

long long req[2 * MAX_ROOMCNT + 1];
long long pSums[2 * MAX_ROOMCNT + 1][2];
long long DP[MAX_ENTRYCNT + 1][2 * MAX_ROOMCNT + 1];

namespace cht {
    vector<pair<long long, long long>> lines;

    inline double intersect(long long m1, long long b1, long long m2, long long b2) {
        return (double)(b2 - b1) / (m1 - m2);
    }
    inline double intersect(pair<long long, long long> a, pair<long long, long long> b) {
        return intersect(a.f, a.s, b.f, b.s);
    }
    inline long long y(pair<long long, long long> a, long long x) {
        return a.f * x + a.s;
    }
    void insert(long long m, long long b) {
        pair<long long, long long> n = make_pair(m, b);
        while (lines.size() >= 2) {
            double w = intersect(lines[lines.size() - 1], n);
            double z = intersect(lines[lines.size() - 2], n);
            if (w > z)
                lines.pop_back();
            else break;
        }
        lines.emplace_back(m, b);
    }
    long long query(long long x) {
        while (lines.size() >= 2 && y(lines[0], x) >= y(lines[1], x))
            lines.erase(lines.begin());
        return y(lines[0], x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");

    long long N, K; cin >> N >> K;
    for (long long i = 0; i < N; i++) {
        cin >> req[i];
        req[i + N] = req[i];
    }
    pair<long long, long long> sum = make_pair(0, 0);
    for (long long i = 0; i < 2 * N; i++) {
        sum.f += req[i]; sum.s += (i + 1) * req[i];
        pSums[i + 1][0] = sum.f; pSums[i + 1][1] = sum.s;
    }

    long long minCost = INF;
    for (long long l = 0; l < N; l++) {
        for (long long k = 0; k <= K; k++)
            for (long long i = l; i <= N + l; i++)
                DP[k][i] = INF;
        DP[0][N + l] = 0;
        for (long long k = 1; k <= K; k++) {
            cht::lines.clear();
            for (long long i = N - 1 + l; i >= l; i--) {
                long long j = i + 1;
                long long m = -pSums[j][0], b = pSums[j][1] + DP[k - 1][j];
                cht::insert(m, b);
                DP[k][i] = -pSums[i][1] + (i + 1) * pSums[i][0] + cht::query(i + 1);
                DP[k][i] = DP[k][i];
            }
        }
        minCost = min(minCost, DP[K][l]);
    }

    cout << minCost << endl;
    return 0;
}

/*
 * for (long long l = 0; l < N; l++) {
        for (long long k = 0; k <= K; k++)
            for (long long i = 0; i <= N; i++)
                DP[k][i] = INF;
        DP[0][N] = 0;
        for (long long k = 1; k <= K; k++) {
            cht::lines.clear();
            for (long long i = N - 1; i >= 0; i--) {
                long long j = i + 1;
                long long m = -pSums[j][0], b = pSums[j][1] + DP[k - 1][j];
                cht::insert(m, b);
                DP[k][i] = -pSums[i][1] + (i + 1) * pSums[i][0] + cht::query(i + 1);
            }
        }
    }
 */
