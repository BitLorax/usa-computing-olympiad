//
// Created by WillJ on 3/29/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_DAYCNT 100

using namespace std;

int record[MAX_DAYCNT];
int DP[MAX_DAYCNT + 1][MAX_DAYCNT + 1][MAX_DAYCNT + 1]; //DP[current day][last index of breakout][number of breakouts] = min changes

int main() {

    ifstream cin ("taming.in");
    ofstream cout ("taming.out");

    int dayCount; cin >> dayCount;
    for (int i = 0; i < dayCount; i++) {
        cin >> record[i];
    }
    for (int i = 0; i <= dayCount; i++) {
        for (int j = 0; j <= dayCount; j++) {
            for (int k = 0; k <= dayCount; k++) {
                DP[i][j][k] = INF;
            }
        }
    }
    DP[0][0][1] = 0;
    for (int i = 0; i < dayCount; i++) { //day
        for (int j = 0; j <= i; j++) { //prev breakout
            for (int k = 1; k <= i + 1; k++) { //number of breakouts
                if (i == j) { //breakout today
                    for (int jj = 0; jj < i; jj++) DP[i][j][k] = min(DP[i][j][k], DP[i - 1][jj][k - 1]);
                } else {
                    DP[i][j][k] = DP[i - 1][j][k];
                }
                if (record[i] != (i - j)) DP[i][j][k]++;
            }
        }
    }
    for (int k = 1; k <= dayCount; k++) {
        int minChanges = INF;
        for (int j = 0; j < dayCount; j++) minChanges = min(minChanges, DP[dayCount - 1][j][k]);
        cout << minChanges << endl;
    }
    return 0;
}
