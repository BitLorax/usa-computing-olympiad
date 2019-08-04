//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_STOPCNT 100000

using namespace std;

struct Stop {
    long long pos, tastiness;
    bool operator<(const Stop &a) const {
        return pos < a.pos;
    }
};

Stop stops[MAX_STOPCNT];
bool shouldStop[MAX_STOPCNT];

int main() {

    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    long long pathLen, stopCount, fR, bR; cin >> pathLen >> stopCount >> fR >> bR;
    for (long long i = 0; i < stopCount; i++) {
        cin >> stops[i].pos >> stops[i].tastiness;
    }
    sort(stops, stops + stopCount);
    long long curMax = 0;
    for (long long i = stopCount - 1; i >= 0; i--) {
        if (stops[i].tastiness > curMax) {
            shouldStop[i] = true;
            curMax = stops[i].tastiness;
        }
    }
    long long bT = 0, fT = 0, lastPos = 0, tastinessGained = 0;
    for (long long i = 0; i < stopCount; i++) {
        fT += fR * (stops[i].pos - lastPos);
        bT += bR * (stops[i].pos - lastPos);
        if (shouldStop[i]) {
            tastinessGained += stops[i].tastiness * (fT - bT);
            bT = fT;
        }
        lastPos = stops[i].pos;
    }
    cout << tastinessGained << endl;
    return 0;
}
