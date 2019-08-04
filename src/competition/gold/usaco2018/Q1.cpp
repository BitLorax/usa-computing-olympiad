//
// Created by WillJ on 4/1/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define INF 2000000000
#define MAX_GROUPCNT 400
#define MAX_CHANGELIMIT 300

using namespace std;

int groups[MAX_GROUPCNT];
int DP[MAX_CHANGELIMIT + 1][MAX_GROUPCNT][MAX_GROUPCNT]; //DP[changes][start of new change][end of new change]
int preSums[MAX_GROUPCNT + 1]; //first i groups

int main() {

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int groupCount, changeLimit; cin >> groupCount >> changeLimit;
    int sum = 0;
    for (int i = 0; i < groupCount; i++) {
        cin >> groups[i];
        preSums[i] = sum;
        sum += groups[i];
    }
    preSums[groupCount] = sum;

    for (int i = 0; i <= changeLimit; i++) {
        for (int j = 0; j < groupCount; j++) {
            for (int k = 0; k < groupCount; k++) {
                DP[i][j][k] = INF;
            }
        }
    }
    int biggest = 0;
    for (int k = 0; k < groupCount; k++) {
        biggest = max(biggest, groups[k]);
        DP[0][0][k] = (k - 0 + 1) * biggest - (preSums[k + 1] - preSums[0]);
    }
    for (int i = 1; i <= changeLimit; i++) {
        for (int j = i; j < groupCount; j++) {
            int bestPrev = INF;
            for (int kk = 0; kk < j; kk++) bestPrev = min(bestPrev, DP[i - 1][kk][j - 1]);
            biggest = 0;
            for (int k = j; k < groupCount; k++) {
                biggest = max(biggest, groups[k]);
                DP[i][j][k] = bestPrev + (k - j + 1) * biggest - (preSums[k + 1] - preSums[j]);
            }
        }
    }
    int minWaste = INF;
    for (int j = changeLimit; j < groupCount; j++) minWaste = min(minWaste, DP[changeLimit][j][groupCount - 1]);
    cout << minWaste << endl;
    return 0;
}