//
// Created by WillJ on 12/31/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_COWCNT 2500

using namespace std;

int times[MAX_COWCNT + 1];
int DP[MAX_COWCNT + 1]; //cows taken

int main() {
    int cowCount; cin >> cowCount >> times[0]; times[0] *= 2;
    for (int i = 1; i <= cowCount; i++) {
        cin >> times[i]; times[i] += times[i - 1];
        DP[i] = INF;
    }
    DP[0] = 0;
    for (int i = 1; i <= cowCount; i++) { //how many FJ plans to take
        for (int j = 1; j <= i; j++) { //choose how many cows to take
            if (DP[i - j] != INF) DP[i] = min(DP[i], DP[i - j] + times[j]);
        }
    }
    cout << DP[cowCount] - (times[0] / 2) << endl;
    return 0;
}
