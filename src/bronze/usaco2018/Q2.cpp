//
// Created by WillJ on 12/14/2018.
//
#include <iostream>
#include <algorithm>

#define MAX_COWCNT 100

using namespace std;

struct ChangePoint {
    int time, bucketsNeeded;
    bool start;
    bool operator<(const ChangePoint &a) const {
        return time < a.time;
    }
};
ChangePoint changePoints[MAX_COWCNT * 2];

int main() {

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        int s, e, b; cin >> s >> e >> b;
        changePoints[i * 2].time = s; changePoints[i * 2].start = true;
        changePoints[i * 2 + 1].time = e; changePoints[i * 2 + 1].start = false;
        changePoints[i * 2].bucketsNeeded = b; changePoints[i * 2 + 1].bucketsNeeded = b;
    }
    sort(changePoints, changePoints + 2 * cowCount);
    int currBuckets = 0;
    int maxBuckets = 0;
    for (int i = 0; i < 2 * cowCount; i++) {
        ChangePoint curr = changePoints[i];
        if (curr.start) currBuckets += curr.bucketsNeeded;
        else currBuckets -= curr.bucketsNeeded;
        maxBuckets = max(maxBuckets, currBuckets);
    }
    cout << maxBuckets << endl;
    return 0;
}
