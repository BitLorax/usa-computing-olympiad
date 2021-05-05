//
// Created by willj on 11/3/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 2000

using namespace std;

int pSum[MAX_N + 1][MAX_N + 1];

int tot(int x, int y, int s) {
    return pSum[x + s][y + s] - pSum[x][y + s] - pSum[x + s][y] + pSum[x][y];
}

int main() {
    int n, w, l; cin >> n >> w >> l;
    for (int i = 0; i < w; i++) {
        int x, y; cin >> x >> y;
        pSum[x][y]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pSum[i + 1][j + 1] += pSum[i + 1][j] + pSum[i][j + 1] - pSum[i][j];
        }
    }
    int maxS = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int lo = 0, hi = n + 1;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (!(i + mid - 1 >= n || j + mid - 1 >= n) && tot(i, j, mid) <= l) lo = mid;
                else hi = mid;
            }
            maxS = max(maxS, lo);
        }
    }
    cout << maxS * maxS << endl;
    return 0;
}
