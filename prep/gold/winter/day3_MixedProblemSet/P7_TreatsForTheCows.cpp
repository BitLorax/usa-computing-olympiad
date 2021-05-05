//
// Created by WillJ on 12/28/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_TREATCNT 2000

using namespace std;

int treats[MAX_TREATCNT];
int DP[MAX_TREATCNT + 1][MAX_TREATCNT + 1];

int sell(int lo, int hi, int age) { //sell either treats[lo] or treats[hi]
    if (DP[lo][hi] > -1) return DP[lo][hi];
    if (lo == hi) {
        DP[lo][hi] = age * treats[lo];
        return DP[lo][hi];
    }
    DP[lo][hi] = max(sell(lo + 1, hi, age + 1) + age * treats[lo], sell(lo, hi - 1, age + 1) + age * treats[hi]);
    return DP[lo][hi];
}

int main() {
    int treatCount; cin >> treatCount;
    for (int i = 0; i < treatCount; i++) {
        cin >> treats[i];
    }
    for (int i = 0; i < treatCount; i++) {
        for (int j = 0; j < treatCount; j++) {
            DP[i][j] = -1;
        }
    }
    cout << sell(0, treatCount - 1, 1) << endl;
    return 0;
}
