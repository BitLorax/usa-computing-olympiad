//
// Created by WillJ on 1/19/2019.
//

#include <iostream>

#define INF 2000000000
#define MAX_PATHLEN 250
#define MAX_BOOTCNT 250

using namespace std;

struct Boot {
    int depth, stepSize;
};

int path[MAX_PATHLEN];
Boot boots[MAX_BOOTCNT];
bool DP[MAX_PATHLEN][MAX_BOOTCNT]; //curTile, curBoot

int main() {

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int pathLen, bootCount; cin >> pathLen >> bootCount;
    for (int i = 0; i < pathLen; i++) {
        cin >> path[i];
    }
    for (int i = 0; i < bootCount; i++) {
        cin >> boots[i].depth >> boots[i].stepSize;
    }
    DP[0][0] = true;
    for (int i = 0; i < pathLen; i++) {
        for (int j = 0; j < bootCount; j++) {
            if (!DP[i][j]) continue;
            for (int k = 1; k <= boots[j].stepSize && i + k < pathLen; k++) {
                if (path[i + k] <= boots[j].depth) {
                    DP[i + k][j] = true;
                }
            }
            for (int k = 1; j + k < bootCount; k++) {
                if (path[i] <= boots[j + k].depth) {
                    DP[i][j + k] = true;
                }
            }
        }
    }
    for (int i = 0; i < bootCount; i++) {
        if (DP[pathLen - 1][i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
