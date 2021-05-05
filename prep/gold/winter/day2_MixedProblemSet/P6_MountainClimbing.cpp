//
// Created by WillJ on 12/27/2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000000
#define MAX_COWCNT 25000

using namespace std;

pair<int, int> cows[MAX_COWCNT];

bool compDiff(pair<int, int> a, pair<int, int> b) {
    if (a.second >= a.first && b.second >= b.first) {
        return a.first < b.first;
    }
    if (a.second < a.first && b.second < b.first) {
        return a.second > b.second;
    }
    return a.second >= a.first;
}

//Keep trying ways to greedy and finding counterexamples

int main() {
    int cowCount; cin >> cowCount;
    int posDiffCount = 0;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].first >> cows[i].second;
        if (cows[i].second >= cows[i].first) posDiffCount++;
    }
    sort(cows, cows + cowCount, compDiff);
    cout << endl;
    int upFree = 0, downFree = cows[0].first;
    int time = 0;
    int cowsFinished = 0, index = 0;
    vector<int> summit;
    while (cowsFinished < cowCount) {
        if (summit.size() > 0 && time >= downFree) {
            downFree += *summit.begin();
            summit.erase(summit.begin());
            cowsFinished++;
        }
        if (index < cowCount && time >= upFree) {
            pair<int, int> cow = cows[index++];
            upFree += cow.first;
            summit.push_back(cow.second);
        }
        if (summit.size() == 1) downFree = max(downFree, upFree);
        if (index == cowCount) time = downFree;
        else time = min(downFree, upFree);
    }
    cout << downFree << endl;
    return 0;
}