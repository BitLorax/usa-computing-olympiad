//
// Created by WillJ on 8/16/2019.
//

#include <iostream>
#include <fstream>
#include <set>

#define MAX_CARDCNT 50000

using namespace std;

int b[MAX_CARDCNT + 1];
int e[MAX_CARDCNT + 1];
int hi[MAX_CARDCNT + 1];
int lo[MAX_CARDCNT + 1];
int seen[MAX_CARDCNT * 2 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");

    int cardCount; cin >> cardCount;
    for (int i = 0; i < cardCount; i++) {
        cin >> e[i];
        e[i]--; seen[e[i]] = true;
    }
    int k = 0;
    for (int i = 0; i < 2 * cardCount; i++) {
        if (!seen[i]) b[k++] = i;
    }

    int wins = 0;
    set<int> bS;
    for (int i = 0; i < cardCount; i++) bS.insert(b[i]);
    for (int i = 0; i < cardCount; i++) {
        auto it = bS.lower_bound(e[i]);
        if (it != bS.end()) {
            bS.erase(it);
            wins++;
        }
        hi[i] = wins;
    }
    bS.clear(); wins = 0;
    for (int i = 0; i < cardCount; i++) bS.insert(b[i]);
    for (int i = cardCount - 1; i >= 0; i--) {
        auto it = bS.lower_bound(e[i]);
        if (it != bS.begin()) {
            bS.erase(--it);
            wins++;
        }
        lo[i] = wins;
    }
    int maxWin = lo[0];
    for (int i = 0; i <= cardCount - 1; i++) {
        maxWin = max(maxWin, hi[i] + lo[i + 1]);
    }
    cout << maxWin << endl;
    return 0;
}
