//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 2000000000
#define MAX_EVENTCNT 10000

using namespace std;

int dists[MAX_EVENTCNT + 1];
int times[MAX_EVENTCNT];

int main() {
    int eventCount; cin >> eventCount;
    int dCount = 0, tCount = 0;
    for (int i = 0; i < eventCount; i++) {
        char a; int b; cin >> a >> b;
        if (a == 'T') times[tCount++] = b;
        else dists[dCount++] = b;
    }
    dists[dCount++] = 1000;
    sort(times, times + tCount);
    sort(dists, dists + dCount);
    double pos = 0;
    double time = 0, speed = 1;
    int d = 0, t = 0;
    while (pos < 1000) {
        if (t == tCount || time + (dists[d] - pos) * speed <= times[t]) { //next slowdown is dist
            time += (dists[d] - pos) * speed;
            pos = dists[d];
            d++, speed++;
        } else {
            pos += (times[t] - time) * (1 / speed);
            time = times[t];
            t++, speed++;
        }
    }
    cout << (int)round(time) << endl;
    return 0;
}
