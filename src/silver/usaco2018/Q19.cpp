//
// Created by WillJ on 12/15/2018.
//

#include <iostream>
#include <algorithm>

#define MAX_COWCOUNT 100000

using namespace std;

int cowTimes[MAX_COWCOUNT];

int main() {

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int cowCount, busCount, busCapacity; cin >> cowCount >> busCount >> busCapacity;
    for (int i = 0; i < cowCount; i++) cin >> cowTimes[i];
    sort(cowTimes, cowTimes + cowCount);
    int busesLeft = busCount - 1;
    int index = 0;
    int maxWait = 0;
    while (busesLeft > 0) {
        pair<int, int> biggestGap;
        for (int i = 0; i < busCapacity; i++) { //greedy?
            if (busesLeft * busCapacity < cowCount - (index + i + 1)) continue;
            if (cowTimes[index + i + 1] - cowTimes[index + i] > biggestGap.first) {
                biggestGap.first = cowTimes[index + i + 1] - cowTimes[index + i];
                biggestGap.second = index + i;
            }
        }
        maxWait = max(maxWait, cowTimes[biggestGap.second] - cowTimes[index]);
        index = biggestGap.second + 1;
        busesLeft--;
    }
    maxWait = max(maxWait, cowTimes[cowCount - 1] - cowTimes[index]);
    cout << maxWait << endl;
    return 0;
}

