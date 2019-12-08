//
// Created by WillJ on 12/15/2018.
//
#include <iostream>
#include <algorithm>

#define MAX_COWCNT 100000
#define MAX_BUSCNT 100000
#define INF 2000000000

using namespace std;

int cowCount, busCount, busCapacity;
int cowTimes[MAX_COWCNT];
int minWaitTime = INF;
int DP[MAX_BUSCNT + 1][MAX_COWCNT + 1];

int calc(int busCount, int cowCount) {
    if (DP[busCount][cowCount] != -1) return DP[busCount][cowCount];
    DP[busCount][cowCount] = min(DP[busCount - 1][cowCount], DP[busCount][cowCount - 1] + (cowTimes[cowCount] - cowTimes[cowCount - 1]));
}


int main() {
    cin >> cowCount >> busCount >> busCapacity;
    for (int i = 0; i < cowCount; i++) cin >> cowTimes[i];
    sort(cowTimes, cowTimes + cowCount);
    for (int i = 0; i <= busCount; i++) {
        for (int j = 0; j <= cowCount; j++) {
            DP[i][j] = -1;
        }
    }
    DP[0][0] = 0;
    cout << calc(busCount, cowCount) << endl;
    return 0;
}

