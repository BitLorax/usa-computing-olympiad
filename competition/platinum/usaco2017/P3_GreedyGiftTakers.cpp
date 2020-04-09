//
// Created by WillJ on 8/26/2019.
//

#include <iostream>
#include <fstream>

#define MAX_COWCNT 100000

using namespace std;

int to[MAX_COWCNT + 1];
int sum[MAX_COWCNT + 1];

bool allGet(int cow) {
    for (int i = 0; i < MAX_COWCNT; i++) sum[i] = 0;
    for (int i = 0; i < cow; i++) sum[to[i]]++;
    int total = 0;
    for (int i = 0; i < MAX_COWCNT; i++) {
        total += sum[i];
        if (total >= i + 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("greedy.in");
    ofstream cout("greedy.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> to[i];
        to[i] = cowCount - 1 - to[i];
    }
    int lo = 0, hi = cowCount;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (allGet(mid)) lo = mid;
        else hi = mid;
    }

    cout << cowCount - (lo + 1) << endl;
    return 0;
}
