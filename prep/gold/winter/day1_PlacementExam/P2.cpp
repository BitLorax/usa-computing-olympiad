//
// Created by WillJ on 12/26/2018.
//


#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

#define MAX_POLECNT 1000

using namespace std;

int poleCount, connectionCount, freeCount;
struct State {
    vector<int> lens;
    int curPole, from;
    bool operator<(const State &a) const { //broken?
        if (a.lens.size() <= freeCount) {
            if (lens.size() <= freeCount) return true;
            return false;
        }
        if (lens.size() <= freeCount) return true;
        return lens[0] < a.lens[0];
    }
};

vector<pair<int, int>> connections[MAX_POLECNT + 1];
int visited[MAX_POLECNT + 1];

int main() {
    cin >> poleCount >> connectionCount >> freeCount;
    for (int i = 0; i < connectionCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections[a].push_back(make_pair(b, c));
        connections[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i <= MAX_POLECNT; i++) {
        visited[i] = -1;
    }
    int minPay = 2000000000;
    priority_queue<State> q;
    vector<int> a;
    q.push(State{a, 1, -1});
    while (!q.empty()) {
        State cur = q.top(); q.pop();
        if (cur.curPole == poleCount) {
            minPay = min(minPay, cur.lens[cur.lens.size() - freeCount - 1]);
            continue;
        }
        if (cur.lens.size() > freeCount) {
            if (visited[cur.curPole] != -1 && visited[cur.curPole] <= cur.lens[0]) continue;
            if (cur.lens[0] >= minPay) continue;
            if (visited[cur.curPole] == -1) {
                visited[cur.curPole] = cur.lens[0];
            } else {
                visited[cur.curPole] = min(visited[cur.curPole], cur.lens[0]);
            }
        }
        vector<pair<int, int>> connection = connections[cur.curPole];
        for (int i = 0; i < connection.size(); i++) {
            if (connection[i].first == cur.from) continue;
            State newState{cur.lens, connection[i].first, cur.curPole};
            newState.lens.push_back(connection[i].second);
            sort(newState.lens.begin(), newState.lens.end());
            while (newState.lens.size() > freeCount + 1) {
                newState.lens.erase(newState.lens.begin());
            }
            if (newState.lens.size() > freeCount) {
                if (visited[newState.curPole] != -1 && visited[newState.curPole] <= newState.lens[0]) continue;
                if (newState.lens[0] >= minPay) continue;
            }
            q.push(newState);
        }
    }
    if (minPay == 2000000000) cout << -1 << endl;
    else cout << minPay << endl;
    return 0;
}