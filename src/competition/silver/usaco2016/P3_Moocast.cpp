//
// Created by WillJ on 2/22/2019.
//

#include <iostream>
#include <queue>
#include <cmath>

#define INF 2000000000
#define MAX_COWCNT 200

using namespace std;

struct Cow {
    int x, y, power;
};

Cow cows[MAX_COWCNT];
bool visited[MAX_COWCNT];

double getDist(int one, int two) {
    return sqrt(abs(cows[one].x - cows[two].x) * abs(cows[one].x - cows[two].x) + abs(cows[one].y - cows[two].y) * abs(cows[one].y - cows[two].y));
}

int main() {

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].x >> cows[i].y >> cows[i].power;
    }
    int maxReached = 0;
    for (int i = 0; i < cowCount; i++) {
        for (int j = 0; j < cowCount; j++) visited[j] = false;
        int reached = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            reached++;
            for (int k = 0; k < cowCount; k++) {
                if (k != cur && getDist(cur, k) <= cows[cur].power) q.push(k);
            }
        }
        maxReached = max(maxReached, reached);
    }
    cout << maxReached << endl;
    return 0;
}
