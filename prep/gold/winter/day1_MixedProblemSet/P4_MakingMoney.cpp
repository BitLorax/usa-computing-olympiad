//
// Created by WillJ on 12/26/2018.
//

#include <iostream>

#define MAX_CURIOCNT 100
#define MAX_BUDGET 1000000

using namespace std;

//pair<int, int> curios[MAX_CURIOCNT];
int costs[MAX_CURIOCNT];
int profits[MAX_CURIOCNT];
int DP[MAX_BUDGET + 1];

int main() {
    int curioCount, budget; cin >> curioCount >> budget;
    for (int i = 0; i < curioCount; i++) {
        //cin >> curios[i].first >> curios[i].second;
        int a, b; cin >> a >> b;
        costs[i] = a; profits[i] = b - a;
    }
    for (int i = 0; i <= MAX_BUDGET; i++) DP[i] = -1;
    DP[0] = 0;
    for (int i = 0; i < curioCount; i++) {
        for (int j = costs[i]; j <= budget; j++) {
            if (DP[j - costs[i]] > -1) {
                DP[j] = max(DP[j], DP[j - costs[i]] + profits[i]);
            }
        }
    }
    int maxProfit = 0;
    for (int i = 0; i <= budget; i++) {
        maxProfit = max(maxProfit, (budget - i) + DP[i]);
    }
    cout << maxProfit << endl;
    return 0;
}

