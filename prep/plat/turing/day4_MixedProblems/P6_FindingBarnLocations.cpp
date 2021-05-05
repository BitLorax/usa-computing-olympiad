//
// Created by willj on 11/3/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#define MAX_S 200

using namespace std;

int c[MAX_S + 1][MAX_S + 1];
int pSum[MAX_S + 1][MAX_S + 1]; //pSum[i][j] sums row j from 0 ... i
int ppSum[MAX_S + 1];

int main() {
    int n, m, r; cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> c[j][i];
            sum += c[j][i];
            pSum[j + 1][i] = sum;
        }
    }
    int res = 0;
    for (int lo = 0; lo < m; lo++) {
        for (int hi = lo; hi < m; hi++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += pSum[hi + 1][i] - pSum[lo][i];
                ppSum[i + 1] = sum;
            }
            for (int i = 0; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (ppSum[j] - ppSum[i] >= r) res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
