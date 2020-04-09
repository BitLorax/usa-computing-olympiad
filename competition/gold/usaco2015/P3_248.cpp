//
// Created by WillJ on 3/31/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_NUMCNT 248

using namespace std;

int nums[MAX_NUMCNT];
int DP[MAX_NUMCNT + 1][MAX_NUMCNT]; //DP[len][starting index] = max num (will be 0 if it's not possible to collapse the interval into one number)

int main() {

    ifstream cin ("248.in");
    ofstream cout ("248.out");

    int numCount; cin >> numCount;
    for (int i = 0; i < numCount; i++) {
        cin >> nums[i];
    }
    int maxNum = 0;
    for (int i = 1; i <= numCount; i++) {
        for (int j = 0; j + (i - 1) < numCount; j++) {
            if (i == 1) DP[i][j] = nums[j];
            else {
                for (int k = 1; k < i; k++) {
                    if (DP[k][j] != 0 && DP[k][j] == DP[i - k][j + k]) {
                        DP[i][j] = max(DP[i][j], DP[k][j] + 1);
                        maxNum = max(maxNum, DP[i][j]);
                    }
                }
            }
        }
    }
    cout << maxNum << endl;
    return 0;
}
