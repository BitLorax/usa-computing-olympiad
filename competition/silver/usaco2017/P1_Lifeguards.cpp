//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <algorithm>
#include <set>

#define INF 2000000000
#define MAX_LIFEGUARDCNT 100000

using namespace std;

struct ChangePt {
    int time, mag, id;
    bool operator<(const ChangePt &a) const {
        return time < a.time;
    }
};

ChangePt changePoints[MAX_LIFEGUARDCNT * 2];
int aloneTime[MAX_LIFEGUARDCNT];

int main() {

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int lifeguardCount; cin >> lifeguardCount;
    for (int i = 0; i < lifeguardCount; i++) {
        cin >> changePoints[i * 2].time >> changePoints[i * 2 + 1].time;
        changePoints[i * 2].mag = 1; changePoints[i * 2 + 1].mag = -1;
        changePoints[i * 2].id = i; changePoints[i * 2 + 1].id = i;
    }
    sort(changePoints, changePoints + 2 * lifeguardCount);
    int prevTime = changePoints[0].time, totalTimeCovered = 0;
    set<int> onGuard;
    for (int i = 0; i < 2 * lifeguardCount; i++) {
        if (!onGuard.empty()) totalTimeCovered += changePoints[i].time - prevTime;
        if (onGuard.size() == 1) {
            aloneTime[*onGuard.begin()] += changePoints[i].time - prevTime;
        }
        if (changePoints[i].mag == 1) {
            onGuard.insert(changePoints[i].id);
        } else {
            onGuard.erase(changePoints[i].id);
        }
        prevTime = changePoints[i].time;
    }
    int minTimeLost = INF;
    for (int i = 0; i < lifeguardCount; i++) {
        minTimeLost = min(minTimeLost, aloneTime[i]);
    }
    cout << totalTimeCovered - minTimeLost << endl;
    return 0;
}
