//
// Created by WillJ on 3/31/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#define INF 1000000000000000000L
#define MAX_COWCNT 50000

using namespace std;

struct Coord {
    int x, y;
    bool operator<(const Coord &a) const {
        return x < a.x;
    }
};

int cowCount;
Coord cows[MAX_COWCNT];
multiset<long long> aX; multiset<long long> aY;
multiset<long long> bX; multiset<long long> bY;

long long getMinArea() {
    long long minArea = INF;
    for (int i = 0; i < cowCount - 1; i++) {
        aX.insert(cows[i].x); aY.insert(cows[i].y);
        bX.erase(bX.find(cows[i].x)); bY.erase(bY.find(cows[i].y));
        if (i + 1 < cowCount && cows[i].x == cows[i + 1].x) continue;
        minArea = min(minArea, ((*aX.rbegin() - *aX.begin()) * (*aY.rbegin() - *aY.begin())) + ((*bX.rbegin() - *bX.begin()) * (*bY.rbegin() - *bY.begin())));
    }
    return minArea;
}

int main() {

    ifstream cin ("split.in");
    ofstream cout ("split.out");

    cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].x >> cows[i].y;
        bX.insert(cows[i].x); bY.insert(cows[i].y);
    }
    long long area = (*bX.rbegin() - *bX.begin()) * (*bY.rbegin() - *bY.begin());

    sort(cows, cows + cowCount);
    aX.clear(); aY.clear();
    bX.clear(); bY.clear();
    for (int i = 0; i < cowCount; i++) {
        bX.insert(cows[i].x); bY.insert(cows[i].y);
    }
    long long minArea = getMinArea();

    for (int i = 0; i < cowCount; i++) {
        int temp = cows[i].x;
        cows[i].x = cows[i].y; cows[i].y = temp;
    }

    sort(cows, cows + cowCount);
    aX.clear(); aY.clear();
    bX.clear(); bY.clear();
    for (int i = 0; i < cowCount; i++) {
        bX.insert(cows[i].x); bY.insert(cows[i].y);
    }
    minArea = min(minArea, getMinArea());

    cout << area - minArea << endl;
    return 0;
}
