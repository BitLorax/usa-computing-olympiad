//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <map>

using namespace std;

map<long long, long long> changePoints;

int main() {

    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    long long manureCount; cin >> manureCount;
    long long curDist = 0;
    for (long long i = 0; i < manureCount; i++) {
        long long from, to; cin >> from >> to;
        curDist += abs(to - from);
        if (abs(to - from) < abs(from - 0)) continue; //always faster to go directly
        changePoints[to] += 2;
        if ((from >= 0 && from <= to) || (from <= 0 && from >= to)) {
            changePoints[2 * to - 2 * from]--; changePoints[2 * from]--;
        }
        if ((from <= 0 && to >= 0) || (from >= 0 && to <= 0)) {
            changePoints[0]--; changePoints[2 * to]--;
        }
    }
    long long curSlope = 0, minDist = curDist;
    long long prevPos = changePoints.begin()->second;
    for (auto it = changePoints.begin(); it != changePoints.end(); it++) {
        curDist += curSlope * abs(prevPos - it->first);
        minDist = min(minDist, curDist);

        curSlope += it->second;
        prevPos = it->first;
    }
    cout << minDist << endl;
    return 0;
}
