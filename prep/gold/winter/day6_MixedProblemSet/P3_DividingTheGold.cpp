//
// Created by WillJ on 12/31/2018.
//

//
// Created by WillJ on 12/31/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_COINCNT 250
#define MAX_VALUE 2000
#define MOD 1000000

using namespace std;

long long coins[MAX_COINCNT];
long long DP[MAX_COINCNT * MAX_VALUE + 1];
bool possible[MAX_VALUE * MAX_VALUE + 1];

int main() {
    long long coinCount; cin >> coinCount;
    long long sum = 0;
    for (long long i = 0; i < coinCount; i++) {
        cin >> coins[i];
        sum += coins[i];
    }
    DP[0] = 1;
    for (long long i = 0; i < coinCount; i++) {
        for (long long j = sum; j >= coins[i]; j--) {
            if (DP[j - coins[i]] != 0) {
                possible[j] = true;
                DP[j] = (DP[j] + DP[j - coins[i]]) % MOD;
//                if (j == sum / 2) {
//                    cout << DP[j] << " - " << DP[j - coins[i]] << endl;
//                }
            }
        }
    }
    long long minDiff = INF, possibilities = 0;
    for (long long j = 0; j <= sum; j++) {
        if (abs(j - (sum - j)) < minDiff && possible[j]) {
            minDiff = abs(j - (sum - j));
            possibilities = DP[j];
        }
    }
    cout << minDiff << endl;
    cout << possibilities << endl;
    return 0;
}
