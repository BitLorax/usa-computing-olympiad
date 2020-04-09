//
// Created by willj on 9/30/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_COWCNT 100000

using namespace std;

pair<int, int> cows[MAX_COWCNT + 1];
vector<int> children[MAX_COWCNT + 1];
int size[MAX_COWCNT + 1];
int pos[MAX_COWCNT + 1];
int ret[MAX_COWCNT + 1];

namespace fenwicks {
    int n;
    int fenwick[MAX_COWCNT + 1];
    void update(int index, int add) {
        for (++index; index <= n; index += index&-index)
            fenwick[index] += add;
    }
    int query(int index) {
        int ans = 0;
        for (++index; index > 0; index -= index&-index)
            ans += fenwick[index];
        return ans;
    }
}

int indx = 0;
int dfs(int cur, int par) {
    pos[cur] = indx++;
    size[cur] = 0;
    for (int i : children[cur]) {
        if (i == par) continue;
        size[cur] += dfs(i, cur);
    }
    return 1 + size[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("promote.in");
    ofstream cout("promote.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].first; cows[i].second = i;
        cows[i].first *= -1;
    }
    sort(cows, cows + cowCount);
    for (int i = 1; i < cowCount; i++) {
        int a; cin >> a; a--;
        children[a].push_back(i);
    }
    dfs(0, -1);
    fenwicks::n = cowCount;
    for (int i = 0; i < cowCount; i++) {
        int cow = cows[i].second;
        ret[cow] = fenwicks::query(pos[cow] + size[cow]) - fenwicks::query(pos[cow]);
        fenwicks::update(pos[cow], 1);
    }
    for (int i = 0; i < cowCount; i++) {
        cout << ret[i] << endl;
    }
    return 0;
}
