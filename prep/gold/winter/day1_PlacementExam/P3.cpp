//
// Created by WillJ on 12/26/2018.
//


#include <iostream>

#define MAX_COWCNT 500
#define MAX_SKILL 9500

using namespace std;

int cows[MAX_COWCNT];
int DP[MAX_COWCNT * MAX_SKILL];

int main() {
    int cowCount, favNum; cin >> cowCount >> favNum;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }
    for (int j = 0; j < MAX_COWCNT * MAX_SKILL; j++) {
        DP[j] = -1;
    }
    DP[0] = 1;
    for (int i = 0; i < cowCount; i++) {
        for (int j = MAX_COWCNT * MAX_SKILL; j >= cows[i]; j--) {
            if (DP[j - cows[i]] > -1) {
                if (DP[j] == -1) DP[j] = 0;
                DP[j] = (DP[j] + DP[j - cows[i]]) % 100000000;
            }
        }
    }
    int sum = 0;
    for (int i = favNum; i < MAX_COWCNT * MAX_SKILL; i+= favNum) {
        if (DP[i] > -1) sum = (sum + DP[i]) % 100000000;
    }
    cout << sum << endl;
    return 0;
}