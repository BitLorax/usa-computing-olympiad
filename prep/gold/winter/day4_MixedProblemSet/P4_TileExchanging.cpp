//
// Created by WillJ on 12/29/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_TILECNT 10
#define MAX_SUM 10000

using namespace std;

int tiles[MAX_TILECNT + 1];
int DP[MAX_TILECNT + 1][MAX_SUM + 1]; //DP[sum][# of tiles used]

int getCost(int tileIndex, int size) {
    return abs(size - tiles[tileIndex]) * abs(size - tiles[tileIndex]);
}

int main() {
    int tileCount, sum; cin >> tileCount >> sum;
    for (int i = 0; i < tileCount; i++) cin >> tiles[i];
    for (int i = 0; i <= sum; i++) {
        DP[0][i] = INF;
    }
    DP[0][0] = 0;

    for (int i = 1; i <= tileCount; i++) {
        for (int j = 0; j <= sum; j++) {
            DP[i][j] = INF;
            for (int k = 0; k * k <= j; k++) {
                if (DP[i - 1][j - k * k] != INF) {
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - k * k] + getCost(i - 1, k));
                }
            }
        }
    }
    cout << ((DP[tileCount][sum] == INF) ? -1 : DP[tileCount][sum]) << endl;
    return 0;
}
