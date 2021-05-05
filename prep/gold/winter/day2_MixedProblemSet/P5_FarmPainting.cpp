//
// Created by WillJ on 12/27/2018.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAX_ENCLOSURECNT 50000

using namespace std;

struct Fence { //vertical
    int y1, y2, x, id;
    bool end;
    bool operator<(const Fence &a) const {
        return x > a.x;
    }
};

Fence fences[MAX_ENCLOSURECNT * 2];

bool within(Fence a, Fence b) { //if a within b,
    return b.y1 <= a.y1 && b.y2 >= a.y2;
}

int main() {
    int enclosureCount; cin >> enclosureCount;
    for (int i = 0; i < enclosureCount; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        fences[i * 2].y1 = y1; fences[i * 2].y2 = y2; fences[i * 2].x = x1; fences[i * 2].end = false;
        fences[i * 2 + 1].y1 = y1; fences[i * 2 + 1].y2 = y2; fences[i * 2 + 1].x = x2; fences[i * 2 + 1].end = true;
        fences[i * 2].id = i; fences[i * 2 + 1].id = i;
    }
    int withinCount = 0;
    priority_queue<Fence> q;
    for (int i = 0;  i < 2 * enclosureCount; i++) q.push(Fence{fences[i].y1, fences[i].y2, fences[i].x, fences[i].id, fences[i].end});
    set<pair<int, int>> active; //stores y, roof(1) or floor(0)
    while (!q.empty()) {
        Fence cur = q.top(); q.pop();
        if (!cur.end) {
            auto it = active.lower_bound(make_pair(cur.y2, -1));
            if (it != active.end() && it->second == 1) withinCount++; //doesn't need to consider this enclosure bc there is bigger one
            else {
                active.insert(make_pair(cur.y2, 1));
                active.insert(make_pair(cur.y1, 0));
            }
        } else {
            if (active.find(make_pair(cur.y2, 1)) == active.end()) continue; //end for enclosed wall
            active.erase(active.find(make_pair(cur.y2, 1)));
            active.erase(active.find(make_pair(cur.y1, 0)));
        }
    }
    cout << enclosureCount - withinCount << endl;
    return 0;
}

/*
 * while (!q.empty() && q.top().x == curX) {
            if (q.top().end) {
                for (int j : active) {
                    if (fences[2 * j].id == q.top().id) continue;
                    if (within(q.top(), fences[2 * j])) {
                        withinCount++;
                        break;
                    }
                }
            }
            temp.push(q.top()); q.pop();
        }
        while (!temp.empty()) {
            if (temp.front().end) {
                active.erase(std::find(active.begin(), active.end(), temp.front().id));
            } else {
                active.push_back(temp.front().id);
            }
            temp.pop();
        }
    }
 */