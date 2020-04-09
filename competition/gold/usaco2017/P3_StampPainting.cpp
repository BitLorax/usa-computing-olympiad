//
// Created by WillJ on 1/14/2019.
//

#include <iostream>

#define INF 2000000000
#define MAX_CANVASLEN 1000000
#define MOD 1000000007

using namespace std;

unsigned long long sums[MAX_CANVASLEN + 1];

//last stamp must take up stampLen length
//all other spots can be any color
//find ways to order last stamp * combinations of different colors by counting number of ways where there's no "last stamp" (no consecutive color >= tampLen)

int main() {

    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    int canvasLen, stampCount, stampLen; cin >> canvasLen >> stampCount >> stampLen;
    sums[0] = 0;
    unsigned long long k = stampCount;
    for (int i = 1; i < stampLen; i++) {
        sums[i] = (k + sums[i - 1]) % MOD;
        k = (k * stampCount) % MOD;
    }
    for (int i = stampLen; i <= canvasLen; i++) {
        sums[i] = (((stampCount - 1) * (sums[i - 1] - sums[i - stampLen] + MOD) % MOD ) + sums[i - 1]) % MOD;
    }
    long long total = 1;
    for (int i = 0; i < canvasLen; i++) total = (total * stampCount) % MOD;
    cout << (MOD + total - (MOD + sums[canvasLen] - sums[canvasLen - 1]) % MOD) % MOD;
    return 0;
}
