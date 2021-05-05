//
// Created by WillJ on 12/26/2018.
//

#include <iostream>

#define MAX_PAIRCNT 300
#define MAX_UPPERTOTAL 350
#define MAX_LOWERTOTAL 350
#define MOD 97654321

using namespace std;

int upperTotal, lowerTotal, pairCount;
char pairs[MAX_PAIRCNT][2];
int DP[MAX_UPPERTOTAL + 1][MAX_LOWERTOTAL + 1][52 + 1];

int toInt(char a) {
    if ((int)(a) > 96) return (int)(a) - 'a';
    return 26 + (a - 'A');
}

int solve(int curPair, int upperTotal, int lowerTotal) {
    if (DP[upperTotal][lowerTotal][toInt(pairs[curPair][1])] > -1) {
        return DP[upperTotal][lowerTotal][toInt(pairs[curPair][1])];
    }
    if (upperTotal == 0 && lowerTotal == 0) return 1;
    int ret = 0;
    for (int i = 0; i < pairCount; i++) {
        if (pairs[curPair][1] == pairs[i][0]) {
            int newUpper = upperTotal, newLower = lowerTotal;
            if ((int)(pairs[i][1]) > 96) { //ASCII
                newLower--;
            } else {
                newUpper--;
            }
            if (newUpper >= 0 && newLower >= 0) {
                ret = (ret + solve(i, newUpper, newLower)) % MOD;
            }
        }
    }
    DP[upperTotal][lowerTotal][toInt(pairs[curPair][1])] = ret;
    return DP[upperTotal][lowerTotal][toInt(pairs[curPair][1])];
}

int main() {
    cin >> upperTotal >> lowerTotal >> pairCount;
    for (int i = 0; i < pairCount; i++) {
        string in; cin >> in;
        pairs[i][0] = in[0]; pairs[i][1] = in[1];
    }
    for (int i = 0; i < MAX_UPPERTOTAL; i++) {
        for (int j = 0; j < MAX_LOWERTOTAL; j++) {
            for (int k = 0; k <= 52; k++) {
                DP[i][j][k] = -1;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < pairCount; i++) {
        int newUpper = upperTotal, newLower = lowerTotal;
        if ((int)(pairs[i][0]) > 96) { //ASCII
            newLower--;
        } else {
            newUpper--;
        }
        if ((int)(pairs[i][1]) > 96) { //ASCII
            newLower--;
        } else {
            newUpper--;
        }
        total = (total + solve(i, newUpper, newLower)) % MOD;
    }
    cout << total << endl;
    return 0;
}

