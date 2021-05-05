//
// Created by WillJ on 12/27/2018.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_BARNCNT 1000

using namespace std;

vector<int> connections[MAX_BARNCNT];
int distances[MAX_BARNCNT + 1];

int main() {
    int barnCount, pathCount; cin >> barnCount >> pathCount;
    for (int i = 0; i < pathCount; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for (int i = 0; i <= MAX_BARNCNT; i++) distances[i] = -1;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (distances[cur.first] > -1) continue;
        distances[cur.first] = cur.second;
        for (int i = 0; i < connections[cur.first].size(); i++) {
            q.push(make_pair(connections[cur.first][i], cur.second + 1));
        }
    }
    int farthestBarn = -1, farthestDist = -1, count = 0;
    for (int i = 1; i <= barnCount; i++) {
        if (distances[i] > farthestDist) {
            farthestBarn = i;
            farthestDist = distances[i];
            count = 1;
        } else if (distances[i] == farthestDist) {
            if (farthestBarn == 1) farthestBarn = i;
            count++;
        }
    }
    cout << farthestBarn << " " << farthestDist << " " << count << endl;
    return 0;
}