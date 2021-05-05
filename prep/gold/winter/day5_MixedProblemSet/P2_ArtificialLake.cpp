//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <queue>
#include <stack>

#define INF 2000000000
#define MAX_LEVELCNT 100000

using namespace std;

struct Level {
    long long width, height, id;
    bool operator<(const Level &a) const {
        return height > a.height;
    }
};

Level levels[MAX_LEVELCNT + 2];
long long r[MAX_LEVELCNT + 2], l[MAX_LEVELCNT + 2];
long long cover[MAX_LEVELCNT + 2];

int main() {
    long long levelCount; cin >> levelCount;
    long long lowest = 0;
    levels[0].height = INF; levels[0].width = -1;
    levels[levelCount + 1].height = INF; levels[levelCount + 1].width = -1; //barriers
    for (long long i = 1; i <= levelCount; i++) {
        cin >> levels[i].width >> levels[i].height;
        levels[i].id = i;
        r[i] = i + 1; l[i] = i - 1;
        if (levels[i].height < levels[lowest].height) {
            lowest = i;
        }
    }

    long long time = 0;
    while (levels[lowest].height != INF) {
        cover[lowest] = (long long)time + (long long)levels[lowest].width;
        r[l[lowest]] = r[lowest]; l[r[lowest]] = l[lowest];
        long long (&minNeighbor)[MAX_LEVELCNT + 2] = (levels[l[lowest]].height < levels[r[lowest]].height) ? l : r;
        time += levels[lowest].width * (levels[minNeighbor[lowest]].height - levels[lowest].height);
        levels[minNeighbor[lowest]].width += levels[lowest].width; //merge
        lowest = minNeighbor[lowest];

        while (lowest >= 1 && lowest <= levelCount && levels[minNeighbor[lowest]].height < levels[lowest].height) { //flow down
            lowest = minNeighbor[lowest];
        }
    }
    
    for (long long i = 1; i <= levelCount; i++) cout << cover[i] << endl;
    return 0;
}

/* RIP
 *
 * for (long long i = 1; i <= levelCount; i++) {
        deque<long long> heights; //stores indices
        levels[i].height++;
        bool passedI
        = false;
        long long j, d = ((i > lowest.first) ? 1 : -1);
        if (i == lowest.first) d = INF;
        for (j = lowest.first; ((i > lowest.first) ? (j >= lowest.first) : (j <= lowest.first)); j += d) {
            if (((i > lowest.first) ? (j > i) : (j < i)) && levels[j].height > levels[i].height) break;
            if (passedI) continue; //only advance j
            if (j == i) passedI = true;
            while (!heights.empty() && levels[j].height > levels[heights.front()].height) heights.pop_front();
            heights.push_front(j);
        }
        long long time = 0, highest = heights.back();
        for (long long k = lowest.first; k != i; k += d) {
            time += levels[k].width * abs(levels[k].height - levels[heights.back()].height);
            if (heights.back() == k) heights.pop_back();
        }
        for (long long k = i; k != j; k += d) {
            time += levels[k].width * abs(levels[k].height - (levels[i].height));
        }
        for (long long k = lowest.first; k >= 1 && k <= levelCount; k -= d) {
            if (k == lowest.first) continue;
            if (levels[k].height >= levels[highest].height) break;
            time += levels[k].width * abs(levels[k].height - levels[highest].height);
        }
        time += levels[i].width;
        cover[i] = time;
        levels[i].height--;

    }
 */
