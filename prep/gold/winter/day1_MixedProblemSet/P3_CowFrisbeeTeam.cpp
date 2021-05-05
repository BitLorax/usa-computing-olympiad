//
// Created by WillJ on 12/26/2018.
//

#include <iostream>

#define MAX_COWCNT 2000
#define MAX_FAVNUM 1000
#define MOD 100000000

using namespace std;

int cows[MAX_COWCNT];
int DP[MAX_FAVNUM + 1];
int changes[MAX_FAVNUM + 1];

int main() {
    int cowCount, favNum; cin >> cowCount >> favNum;
    int sum = 0;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
        sum += cows[i];
    }
    for (int j = 0; j < MAX_FAVNUM; j++) {
        DP[j] = -1;
    }
    DP[0] = 1;
    for (int i = 0; i < cowCount; i++) {
        for (int j = 0; j < favNum; j++) {
            if (DP[j] > -1) {
                changes[(j + cows[i]) % favNum] = (changes[(j + cows[i]) % favNum] + DP[j]) % MOD;
            }
        }
        for (int j = 0; j < favNum; j++) {
            if (DP[j] == -1 && changes[j] > 0) DP[j] = 0;
            DP[j] = (DP[j] + changes[j]) % MOD;
            changes[j] = 0;
        }
    }
    cout << (DP[0] - 1) % MOD << endl;
    return 0;
}