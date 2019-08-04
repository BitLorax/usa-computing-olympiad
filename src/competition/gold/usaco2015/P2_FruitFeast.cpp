//
// Created by WillJ on 6/30/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_MAXFULL 5000000

using namespace std;

bool DP[MAX_MAXFULL + 1][2];

int main() {

    ifstream cin ("feast.in");
    ofstream cout ("feast.out");

    int maxFull, orange, lemon; cin >> maxFull >> orange >> lemon;
    DP[0][0] = true;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i <= maxFull; i++) {
            if (!DP[i][j]) continue;
            if (i + orange <= maxFull) DP[i + orange][j] = true;
            if (i + lemon <= maxFull) DP[i + lemon][j] = true;
            if (j == 0) DP[i / 2][j + 1] = true;
        }
    }
    for (int i = maxFull; i >= 0; i--) {
        if (DP[i][0] || DP[i][1]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
