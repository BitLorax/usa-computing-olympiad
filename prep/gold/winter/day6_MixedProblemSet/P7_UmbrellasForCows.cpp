//
// Created by WillJ on 12/31/2018.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_COWCNT 5000
#define MAX_STALLCNT 100000 //defines size of largest umbrella

using namespace std;

int locs[MAX_COWCNT];
int uCosts[MAX_STALLCNT + 1];
int minCosts[MAX_STALLCNT + 1]; //min cost to cover i stalls
int DP[MAX_STALLCNT + 1]; //cows covered with min cost

int main() {
    int cowCount, stallCount; cin >> cowCount >> stallCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> locs[i];
    }
    for (int i = 1; i <= stallCount; i++) {
        cin >> uCosts[i];
    }
    sort(locs, locs + cowCount);
    int minCost = INF;
    for (int i = stallCount; i >= 1; i--) {
        minCost = min(minCost, uCosts[i]);
        minCosts[i] = minCost;
    }
    for (int i = 0; i <= cowCount; i++) DP[i] = INF;
    DP[0] = 0;
    for (int i = 1; i <= cowCount; i++) {
        for (int j = 0; j < i; j++) {
            DP[i] = min(DP[i], DP[j] + minCosts[abs(locs[i - 1] - locs[j]) + 1]);
        }
    }
    cout << DP[cowCount] << endl;
    return 0;
}
