//
// Created by Will Liang on 9/8/2018.
//

#include <iostream>
#include <map>

#define INF 20000000000000
#define MAX_MEALCNT 100000

using namespace std;

pair<long long, long long> mealInfo[MAX_MEALCNT + 10];
map<long long, int> seen;

void update(long long key, int change) {
    seen.insert(pair<long long, int>(key, 0));
    int newVal = seen.find(key)->second + change;
    if (newVal == 0) {
        seen.erase(seen.find(key));
    } else {
        seen.find(key)->second = newVal;
    }
}

int main() {

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    long long mealCount, minFlavor; cin >> mealCount >> minFlavor;
    for (int i = 0; i < mealCount; i++) {
        cin >> mealInfo[i].first >> mealInfo[i].second;
    }
    int right = 0;
    long long total = 0;
    long long minSpicy = INF;
    for (int i = 0; i < mealCount; i++) {
        while (total < minFlavor) {
            if (right >= mealCount) break;
            update(mealInfo[right].second, 1);
            total += mealInfo[right++].first;
        }
        if (total < minFlavor) break;
        minSpicy = min(minSpicy, seen.rbegin()->first);
        total -= mealInfo[i].first;
        update(mealInfo[i].second, -1);
    }
    cout << minSpicy << endl;
    return 0;
}
