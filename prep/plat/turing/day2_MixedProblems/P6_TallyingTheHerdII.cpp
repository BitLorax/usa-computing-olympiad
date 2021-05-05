//
// Created by willj on 10/19/2019.
//

#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

vector<int> connections[MAX_N + 1];
vector<int> order[2];
vector<int> idLoc[MAX_N + 1];
vector<int> rLoc[MAX_N + 1];

void dfs(int cur, int r = 0, int par = -1) {
    order[0].push_back(cur);
    order[1].push_back(r);
    for (int i : connections[cur]) {
        if (i != par) dfs(i, r + 1, cur);
    }
    order[0].push_back(cur);
    order[1].push_back(r);
}

int main() {
    int n; cin >> n;
    bool r = true;
    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        char a; cin >> a;
        int b, c; cin >> b >> c;
        if (r && a == 'P') { //queries begin
            dfs(1);
            for (int j = 0; j < order[0].size(); j++) {
                idLoc[order[0][j]].push_back(j);
                rLoc[order[1][j]].push_back(j);
                maxRank = max(maxRank, order[1][j]);
            }
            for (int j = 0; j <= maxRank; j++) {
                rLoc[j].push_back(order[0].size());
            }
            r = false;
        }
        if (r) connections[c].push_back(b);
        if (!r) {
            int rank = order[1][idLoc[b][0]];
            int targ = rank + c + 1;
            if (targ > maxRank) cout << 0 << endl;
            else {
                int lo = lower_bound(rLoc[targ].begin(), rLoc[targ].end(), idLoc[b][0]) - rLoc[targ].begin();
                int hi = lower_bound(rLoc[targ].begin(), rLoc[targ].end(), idLoc[b][1]) - rLoc[targ].begin();
                cout << (hi - lo) / 2 << endl;
            }
        }
    }
    return 0;
}
