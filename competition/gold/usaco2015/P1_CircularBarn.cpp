//
// Created by willj on 9/12/2019.
//

#include <iostream>
#include <fstream>

#define MAX_COWCNT 100000

using namespace std;

int cows[2 * MAX_COWCNT + 1];

int sumSquares(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
        cows[i + cowCount] = cows[i];
    }
    int curCows = 0;
    int i = 0;
    for (; ; i++) {
        curCows = max(0, curCows + cows[i % cowCount] - 1);
        if (curCows == 0 && i >= cowCount) break;
    }
    i++;
    long long sum = 0;
    for (int k = 0; k < cowCount; k++) {
        sum += sumSquares(curCows + cows[(i + k) % cowCount] - 1) - sumSquares(curCows - 1);
        curCows = curCows + cows[(i + k) % cowCount] - 1;
    }
    cout << sum << endl;
    return 0;
}
