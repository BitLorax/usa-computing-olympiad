//
// Created by WillJ on 12/2/2018.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_BARNCNT 100000

using namespace std;

vector<int> connections[MAX_BARNCNT + 1];
int distFromRoot[MAX_BARNCNT + 1];
int distFromEscape[MAX_BARNCNT + 1];

int main() {

    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int barnCount, start; cin >> barnCount >> start;
    for (int i = 0; i < barnCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for (int i = 0; i <= MAX_BARNCNT; i++) {
        distFromRoot[i] = -1; distFromEscape[i] = -1;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0)); //<currCoord, dist from start>
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        if (distFromRoot[curr.first] != -1) continue;
        distFromRoot[curr.first] = curr.second;
        for (int i : connections[curr.first]) {
            q.push(make_pair(i, curr.second + 1));
        }
    }
    for (int i = 1; i <= barnCount; i++) {
        if (i != start && connections[i].size() == 1) { //is escape barn
            q.push(make_pair(i, 0)); //<currCoord, dist from nearest escape>
        }
    }
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        if (distFromEscape[curr.first] != -1) continue;
        distFromEscape[curr.first] = curr.second;
        for (int i : connections[curr.first]) {
            q.push(make_pair(i, curr.second + 1));
        }
    }
    int farmersNeeded = 0;
    q.push(make_pair(start, - 1)); //<currCoord, parent>
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        if (curr.second != -1) { //is not root
            if (distFromRoot[curr.second] < distFromEscape[curr.second]) { //Bessie can reach parent barn safely
                if (distFromRoot[curr.first] >= distFromEscape[curr.first]) {
                    farmersNeeded++;
                }
            }
        }
        for (int i : connections[curr.first]) {
            if (i != curr.second) q.push(make_pair(i, curr.first));
        }
    }
    cout << farmersNeeded << endl;
    return 0;
}

