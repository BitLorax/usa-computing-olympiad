//
// Created by WillJ on 12/29/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_BUDGET 2000
#define MOD 1000000000000

using namespace std;

pair<unsigned long long, unsigned long long> DP[MAX_BUDGET + 1]; //num = .first + MOD * .second

int main() {
    long long budget, toolCount; cin >> budget >> toolCount;
    DP[0].first = 1;
    for (long long cost = 1; cost <= toolCount; cost++) {
        for (long long i = cost; i <= budget; i++) {
            if (DP[i - cost].first > 0 || DP[i - cost].second > 0) {
                DP[i].first += DP[i - cost].first;
                DP[i].second += DP[i - cost].second;
                if (DP[i].first >= MOD) {
                    DP[i].first %= MOD;
                    DP[i].second++;
                }
            }
        }
    }
    unsigned long len = to_string(DP[budget].first).size();
    if (DP[budget].second > 0) {
        cout << DP[budget].second;
        for (int i = 0; i < 12 - len; i++) cout << "0";
    }
    cout << DP[budget].first;
    return 0;
}