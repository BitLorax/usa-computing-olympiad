//
// Created by WillJ on 12/15/2018.
//
#include <iostream>
#include <algorithm>

#define MAX_COWCNT 100000
#define MAX_BUSCNT 100000
#define INF 2000000000

using namespace std;

int cowCount, busCount, busCapacity;
int cowTimes[MAX_COWCNT];
int minWaitTime = INF;

void split(int numGroups, int start, int end, int waitTime) {
    if (waitTime >= minWaitTime) return;
    if (end == cowCount) {
        minWaitTime = waitTime;
        return;
    }
    if (numGroups != busCount) { //can split
        if (end - start + 1 == busCapacity) { //has to split
            split(numGroups + 1, end + 1, end + 1, waitTime);
            return;
        }
        split(numGroups, start, end + 1, max(waitTime, cowTimes[end] - cowTimes[start]));
        split(numGroups + 1, end + 1, end + 1, waitTime);
        return;
    } else {
        if (end - start + 1 > busCapacity) return;
        split(numGroups, start, end + 1, max(waitTime, cowTimes[end] - cowTimes[start]));
        return;
    }
}

int main() {

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> cowCount >> busCount >> busCapacity;
    for (int i = 0; i < cowCount; i++) cin >> cowTimes[i];
    sort(cowTimes, cowTimes + cowCount);
    split(1, 0, 0, 0);
    cout << minWaitTime << endl;
    return 0;
}
