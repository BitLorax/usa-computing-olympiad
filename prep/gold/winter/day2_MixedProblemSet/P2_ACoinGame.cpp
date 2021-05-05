//
// Created by WillJ on 12/27/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_COINCNT 2000

using namespace std;

int coinCount;
int coins[MAX_COINCNT];
int preSums[MAX_COINCNT + 1];
int DP[MAX_COINCNT + 1][2 * MAX_COINCNT + 1];

int solve(int coinsLeft, int oppoTaken) {
    if (DP[coinsLeft][oppoTaken] > -1) return DP[coinsLeft][oppoTaken];
    int minOppoProfit = INF;
    for (int i = 1; i <= 2 * oppoTaken && i <= coinsLeft; i++) { //i is how many coins to take
        minOppoProfit = min(minOppoProfit, solve(coinsLeft - i, i));
    }
    DP[coinsLeft][oppoTaken] = preSums[coinsLeft] - minOppoProfit;
    return DP[coinsLeft][oppoTaken];
}

int main() {
    cin >> coinCount;
    for (int i = 0; i < coinCount; i++) {
        cin >> coins[i];
    }
    int j = coinCount - 1;
    for (int i = 1; i <= coinCount; i++) {
        preSums[i] = preSums[i - 1] + coins[j--];
    }
    for (int i = 1; i <= MAX_COINCNT; i++) {
        for (int j = 0; j <= 2 * MAX_COINCNT; j++) {
            DP[i][j] = -1;
        }
    }
    cout << solve(coinCount, 1) << endl;
    return 0;
}
