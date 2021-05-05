//
// Created by WillJ on 12/26/2018.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_POLECNT 1000
#define MAX_LEN 1000000

using namespace std;

int poleCount, connectionCount, freeCount;
vector<pair<int, int>> connections[MAX_POLECNT + 1];
int visited[MAX_POLECNT + 1];

struct State {
    int curPole, freePolesLeft;
};

bool possible(int maxLen) { //anything higher than maxLen needs to be free
    for (int i = 0; i < MAX_POLECNT; i++) visited[i] = -1;
    queue<State> q;
    q.push(State{1, freeCount});
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.curPole == poleCount) {
            return true;
        }
        if (visited[cur.curPole] >= cur.freePolesLeft) continue;
        visited[cur.curPole] = cur.freePolesLeft;
        for (int i = 0; i < connections[cur.curPole].size(); i++) {
            State newState{connections[cur.curPole][i].first, cur.freePolesLeft};
            if (connections[cur.curPole][i].second > maxLen) {
                newState.freePolesLeft--;
            }
            if (newState.freePolesLeft >= 0) q.push(newState);
        }
    }
    return false;
}

int main() {
    cin >> poleCount >> connectionCount >> freeCount;
    for (int i = 0; i < connectionCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections[a].push_back(make_pair(b, c));
        connections[b].push_back(make_pair(a, c));
    }
    int lo = 0, hi = MAX_LEN, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo == MAX_LEN) cout << -1 << endl;
    else cout << lo << endl;
    return 0;
}

