//
// Created by WillJ on 2/23/2019.
//

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <bitset>

#define INF 2000000000
#define MAX_PASTURECNT 100000

using namespace std;

vector<pair<int, bool>> connections[MAX_PASTURECNT + 1]; //<target, same>
int simulation[MAX_PASTURECNT + 1];
bool visited[MAX_PASTURECNT + 1];

int main() {

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int pastureCount, connectionCount; cin >> pastureCount >> connectionCount;
    int start = -1;
    for (int i = 0; i < connectionCount; i++) {
        string a; int b, c; cin >> a >> b >> c;
        if (i == 0) start = b;
        connections[b].push_back(make_pair(c, (a == "S")));
        connections[c].push_back(make_pair(b, (a == "S")));
    }
    //test if possible
    if (start != -1) {
        queue<pair<int, int>> q; //<pasture, color it should be>
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first > MAX_PASTURECNT) break;
            if (simulation[cur.first] != 0 && simulation[cur.first] != cur.second) {
                cout << "0" << endl;
                return 0;
            }
            if (simulation[cur.first] != 0) continue;
            simulation[cur.first] = cur.second;
            for (pair<int, bool> i : connections[cur.first]) {
                q.push(make_pair(i.first, ((i.second) ? cur.second : ((cur.second == 1) ? 2 : 1))));
            }
        }
    }
    int l = 0;
    for (int i = 1; i <= pastureCount; i++) {
        if (visited[i]) continue;
        l++;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            for (pair<int, bool> j : connections[cur]) {
                q.push(j.first);
            }
        }
    }
    cout << "1";
    for (int i = 0; i < l; i++) {
        cout << "0";
    }
    cout << endl;
    return 0;
}
