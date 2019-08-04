//
// Created by Will Liang on 8/23/2018.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct State {
    int mirrorsUsed, pos;
    bool horizontal;
    State(int m, int a, bool c) {
        mirrorsUsed = m;
        pos = a;
        horizontal = c;
    }
    bool operator<(const State &a) const {
        return mirrorsUsed > a.mirrorsUsed;
    }
};

map<int, vector<pair<int, int>>> XtoY;
map<int, vector<pair<int, int>>> YtoX;

bool visited[100010][2];

int main() {

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    int postCount; cin >> postCount;
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    for (int i = 0; i < postCount; i++) {
        int j, k;
        cin >> j >> k;
        XtoY[j].push_back(make_pair(k, i));
        YtoX[k].push_back(make_pair(j, i));
    }
    int ans = -1;
    priority_queue<State> states;
    states.push(State{0, startY, true});
    states.push(State{0, startX, false});
    while (!states.empty()) {
        State curr = states.top();
        states.pop();
        if ((curr.horizontal && curr.pos == endY) | (!curr.horizontal && curr.pos == endX)) {
            ans = curr.mirrorsUsed;
            break;
        }
        vector<pair<int, int>> source = (curr.horizontal) ? YtoX[curr.pos] : XtoY[curr.pos];
        if (!source.empty()) {
            int k = 0;
            for (pair<int, int> next : source) {
                if (visited[next.second][(!curr.horizontal) ? 0 : 1]) continue;
                visited[next.second][(!curr.horizontal) ? 0 : 1] = true;
                states.push(State{curr.mirrorsUsed + 1, next.first, !curr.horizontal});
                k++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
