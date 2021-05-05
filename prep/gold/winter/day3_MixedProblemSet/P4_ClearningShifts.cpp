//
// Created by WillJ on 12/28/2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define INF 2000000000
#define MAX_COWCNT 10000
#define MAX_TIME 86399

using namespace std;

struct ChangePt {
    int time, cost, id;
    bool operator<(const ChangePt &a) const {
        if (time == a.time) return cost != -1;
        return time < a.time;
    }
};

int cowCount, startT, endT;
ChangePt changePoints[MAX_COWCNT * 2];

int main() {
    cin >> cowCount >> startT >> endT; endT++;
    for (int i = 0; i < cowCount; i++) {
        int a, b, c; cin >> a >> b >> c; b++;
        changePoints[i * 2].time = a; changePoints[i * 2].cost = c;
        changePoints[i * 2 + 1].time = b; changePoints[i * 2 + 1].cost = -1;
        changePoints[i * 2].id = i; changePoints[i * 2 + 1].id = i;
    }
    sort(changePoints, changePoints + 2 * cowCount);
    set<pair<int, int>> active; //<cost, id>
    int index = 0;
    for (index = 0; index < cowCount * 2; index++) {
        if (changePoints[index].time != startT) break;
        active.insert(make_pair(changePoints[index].cost, changePoints[index].id));
    }
    if (index == 0) { //cannot start
        cout << -1 << endl;
        return 0;
    }
    for (index; index < cowCount * 2; index++) {
        if (active.empty()) { //impossible to cover all
            cout << -1 << endl;
            break;
        }
        int curTime = changePoints[index].time;
        if (curTime == endT) {
            cout << active.begin()->first << endl;
            return 0;
        }
        while (index < cowCount * 2 && changePoints[index].time == curTime) {
            if (changePoints[index].cost == -1) {
                for (auto it = active.begin(); it != active.end(); it++) {
                    if (it->second == changePoints[index].id) {
                        active.erase(it);
                        break;
                    }
                }
            } else {
                active.insert(make_pair(active.begin()->first + changePoints[index].cost, changePoints[index].id));
            }
            index++;
        }
        index--;
    }
    return 0;
}
