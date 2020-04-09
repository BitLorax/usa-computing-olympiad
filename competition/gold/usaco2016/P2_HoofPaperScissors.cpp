//
// Created by Will Liang on 8/25/2018.
//
#include <iostream>
#include <map>

using namespace std;

int moves[100010];
int states[100010][21][3];

int wins(int a, int b) { //if a beats b
    return ((a + 1) % 3 == b) ? 1 : 0;
}

int main() {

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int gameCount, switchCount; cin >> gameCount >> switchCount;
    map<char, int> toInt;
    toInt['P'] = 0;
    toInt['H'] = 1;
    toInt['S'] = 2;
    for (int i = 0; i < gameCount; i++) {
        char j; cin >> j;
        moves[i] = toInt[j];
    }
    for (int i = 0; i <= gameCount; i++) {
        for (int j = 0; j <= switchCount; j++) {
            for (int k = 0; k < 3; k++) {
                states[i][j][k] = -2000000000;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        states[0][0][i] = 0;
    }
    /* WHY DOESN'T THIS WORK?
    for (int i = 0; i <= gameCount; i++) {
        for (int j = 0; j <= switchCount; j++) {
            for (int k = 0; k < 3; k++) {
                states[i + 1][j][k] = max(states[i + 1][j][k], states[i][j][k] + wins(k, moves[i]));

                int otherOne = (k + 1) % 3;
                int otherTwo = (k + 2) % 3;
                states[i + 1][j + 1][otherOne] = max(states[i + 1][j + 1][otherOne], states[i][j][k] + wins(otherOne, moves[i]));
                states[i + 1][j + 1][otherTwo] = max(states[i + 1][j + 1][otherTwo], states[i][j][k] + wins(otherTwo, moves[i]));
            }
        }
    }
     */
    for (int i = 1; i <= gameCount; i++) {
        for (int j = 0; j <= switchCount; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == 0) {
                    states[i][j][k] = states[i - 1][j][k] + wins(k, moves[i - 1]);
                } else {
                    int otherOne = (k + 1) % 3;
                    int otherTwo = (k + 2) % 3;
                    states[i][j][k] = max(states[i - 1][j][k] + wins(k, moves[i - 1]), max(states[i - 1][j - 1][otherOne] + wins(otherOne, moves[i - 1]), states[i - 1][j - 1][otherTwo] + wins(otherTwo, moves[i - 1])));
                }
            }
        }
    }
    cout << max(states[gameCount][switchCount][0], max(states[gameCount][switchCount][1], states[gameCount][switchCount][2])) << endl;
    return 0;
}
