//
// Created by WillJ on 2/23/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_SIDE 1000
#define MAX_LAYERCNT 100000

using namespace std;

struct ChangePt {
    int x, y1, y2, change;
    bool operator<(const ChangePt &a) const {
        return x < a.x;
    }
};

ChangePt changePts[MAX_LAYERCNT * 2];
int curStrip[MAX_SIDE + 1];

int main() {

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int layerCount, optimalLayer; cin >> layerCount >> optimalLayer;
    for (int i = 0; i < layerCount; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        changePts[i * 2].x = x1; changePts[i * 2].y1 = y1; changePts[i * 2].y2 = y2; changePts[i * 2].change = 1;
        changePts[i * 2 + 1].x = x2; changePts[i * 2 + 1].y1 = y1; changePts[i * 2 + 1].y2 = y2; changePts[i * 2 + 1].change = -1;
    }
    sort(changePts, changePts + 2 * layerCount);
    int area = 0;
    for (int i = 0; i < 2 * layerCount - 1; i++) {
        ChangePt cur = changePts[i];
        int optimal = 0;
        for (int j = cur.y1; j < cur.y2; j++) {
            curStrip[j] += cur.change;
        }
        for (int j = 0; j <= MAX_SIDE; j++) {
            if (curStrip[j] == optimalLayer) optimal++;
        }
        area += ((changePts[i + 1].x - changePts[i].x) * optimal);
    }
    cout << area << endl;
    return 0;
}
