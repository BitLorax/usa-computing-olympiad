//
// Created by WillJ on 12/28/2018.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_MOVECNT 100000

using namespace std;

struct ChangePt {
    int pos, mag;
    bool operator<(const ChangePt &a) const {
        return pos < a.pos;
    }
};

pair<int, int> coats[MAX_MOVECNT];
ChangePt changePoints[MAX_MOVECNT * 2];

int main() {
    int moveCount, requirement; cin >> moveCount >> requirement;
    int curPos = 0;
    for (int i = 0; i < moveCount; i++) {
        int mag; cin >> mag;
        char direc; cin >> direc;
        if (direc == 'L') mag *= -1;
        int newPos = curPos + mag;
        coats[i].first = min(curPos, newPos);
        coats[i].second = max(curPos, newPos);
        curPos = newPos;
    }
    for (int i = 0; i < moveCount; i++) {
        changePoints[i * 2].pos = coats[i].first; changePoints[i * 2].mag = 1;
        changePoints[i * 2 + 1].pos = coats[i].second; changePoints[i * 2 + 1].mag = -1;
    }
    sort(changePoints, changePoints + 2 * moveCount);
    int area = 0;
    int curCoat = 0, prevLoc = -INF;
    for (int i = 0; i < 2 * moveCount; i++) {
        int curLoc = changePoints[i].pos;
        if (prevLoc != -INF && curCoat >= requirement) {
            area += (curLoc - prevLoc);
        }
        while (i < 2 * moveCount && changePoints[i].pos == curLoc) {
            curCoat += changePoints[i++].mag;
        }
        i--;
        prevLoc = curLoc;
    }
    cout << area << endl;
    return 0;
}
