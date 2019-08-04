//
// Created by Will Liang on 8/19/2018.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;


int baleLocs[50000];
int powerRight[50000];
int powerLeft[50000];
int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int baleCount; cin >> baleCount;
    for (int i = 0; i < baleCount; i++) {
        cin >> baleLocs[i];
    }
    sort(baleLocs, baleLocs + baleCount);

    for (int i = 0; i < baleCount; i++) {
        powerRight[i] = 2000000000;
        powerLeft[i] = 2000000000;
    }

    powerRight[baleCount - 1] = -1;
    powerLeft[0] = -1;
    int k = baleCount - 1;
    for (int i = baleCount - 2; i >= 0; i--) {
        while (k - 1 > i && abs(baleLocs[k - 1] - baleLocs[i]) >= powerRight[k - 1] + 1) {
            k--;
        }
        powerRight[i] = min(abs(baleLocs[i] - baleLocs[k]), powerRight[k - 1] + 1);
        /*choose either
         * a: the node whose requirement is less than the distance to it (dist > dp)
         * b: the node whose requirement is greater than the distance to it (dp > dist)
         *
         * in other words, choose the minimum of the distance to a node (that works) or what a closer node requires
        */
    }
    k = 0;
    for (int i = 1; i < baleCount; i++) {
        while (k + 1 < i && abs(baleLocs[k + 1] - baleLocs[i]) >= powerLeft[k + 1] + 1) {
            k++;
        }
        powerLeft[i] = min(abs(baleLocs[i] - baleLocs[k]), powerLeft[k + 1] + 1);
    }
    double minPwr = 2000000000;
    int lo = 0;
    int hi = baleCount - 1;
    while (lo < hi) {
        double pwr = max(abs(double(baleLocs[lo] - baleLocs[hi])) / 2, double(max(powerLeft[lo], powerRight[hi]) + 1));
        minPwr = min(minPwr, pwr);
        if (powerLeft[lo + 1] < powerRight[hi - 1]) {
            lo++;
        } else {
            hi--;
        }
    }
    cout << std::fixed << std::setprecision(1) << minPwr;
    return 0;
}

