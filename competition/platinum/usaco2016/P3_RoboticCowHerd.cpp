//
// Created by WillJ on 9/1/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_LOCCNT 100000

using namespace std;

int locCount, req;
long long made = 0, save = 0;
vector<int> costs[MAX_LOCCNT + 1]; //diff between it and first
int firstCosts[MAX_LOCCNT + 1];

void test(long long bud, int indx) {
    if (made >= req) return;
    if (indx != -1 && firstCosts[indx] > bud) indx = upper_bound(firstCosts, firstCosts + locCount, bud) - firstCosts - 1;
    if (indx == -1) {
        made++;
        return;
    }
    test(bud, indx - 1);
    for (int i = 0; i < costs[indx].size(); i++) {
        if (costs[indx][i] > bud) break;
        test(bud - costs[indx][i], indx - 1);
    }
}

void iterate(long long bud, int indx) {
    if (indx != -1 && firstCosts[indx] > bud) indx = upper_bound(firstCosts, firstCosts + locCount, bud) - firstCosts - 1;
    if (indx == -1) {
        save += bud;
        return;
    }
    iterate(bud, indx - 1);
    for (int i = 0; i < costs[indx].size(); i++) {
        if (costs[indx][i] > bud) break;
        iterate(bud - costs[indx][i], indx - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("src/competition/test.in");
    ofstream cout("src/competition/test.out");

    cin >> locCount >> req;
    long long base = 0, max = 0;
    for (int i = 0; i < locCount; i++) {
        int s; cin >> s;
        vector<int> cur;
        for (int j = 0; j < s; j++) {
            int a; cin >> a;
            cur.push_back(a);
        }
        sort(cur.begin(), cur.end());
        base += cur[0];
        if (s == 1) {
            locCount--; i--;
            continue;
        }
        for (int j = 1; j < s; j++) {
            costs[i].push_back(cur[j] - cur[0]);
        }
        max += costs[i].back();
    }
    sort(costs, costs + locCount);
    for (int i = 0; i < locCount; i++) firstCosts[i] = costs[i][0];

    long long lo = 0, hi = max;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        made = 0; test(mid, locCount - 1);
        if (made >= req) hi = mid;
        else lo = mid + 1;
    }

    iterate(lo - 1, locCount - 1);
    //(lo - 1, ...) weird heuristic to avoid results that add 0 in (lo, ...) while making up the -1 with +1 in collation
    //speeds up runtime with pruning
    cout << (base + lo) * req - save << endl;
    return 0;
}
