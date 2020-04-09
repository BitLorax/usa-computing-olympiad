//
// Created by WillJ on 2/22/2019.
//

#include <iostream>
#include <algorithm>
#include <set>

#define INF 2000000000
#define MAX_COWCNT 20000

using namespace std;

struct Cow {
    int lo, hi;
    bool operator<(const Cow &a) const {
        if (hi == a.hi) return lo < a.lo;
        return hi < a.hi;
    }
};

Cow cows[MAX_COWCNT];
multiset<int> chickens;

int main() {

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int chickenCount, cowCount; cin >> chickenCount >> cowCount;
    for (int i = 0; i < chickenCount; i++) {
        int a; cin >> a;
        chickens.insert(a);
    }
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].lo >> cows[i].hi;
    }
    sort(cows, cows + cowCount);
    int maxPairs = 0;
    for (int i = 0; i < cowCount; i++) {
        auto chicken = chickens.lower_bound(cows[i].lo); //earliest chicken that fits
        if (chicken != chickens.end() && *chicken <= cows[i].hi) {
            maxPairs++;
            chickens.erase(chicken);
        }
    }
    cout << maxPairs << endl;
    return 0;
}
