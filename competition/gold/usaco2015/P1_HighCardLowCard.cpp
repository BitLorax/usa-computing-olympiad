//
// Created by WillJ on 6/30/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define INF 2000000000
#define MAX_CARDCNT 50000

using namespace std;

vector<int> bTop, bBottom;
int eCards[MAX_CARDCNT];
bool cards[MAX_CARDCNT * 2 + 1];

int main() {

    ifstream cin ("cardgame.in");
    ofstream cout ("cardgame.out");

    int cardCount; cin >> cardCount;
    for (int i = 0; i < cardCount; i++) {
        int a; cin >> a;
        eCards[i] = a;
        cards[a] = true;
    }
    for (int i = 2 * cardCount; i >= 1; i--) {
        if (!cards[i]) {
            if (bTop.size() < cardCount / 2) bTop.push_back(i);
            else bBottom.push_back(-i);
        }
    }

    sort(bTop.begin(), bTop.end());
    sort(bBottom.begin(), bBottom.end());
    sort(eCards, eCards + cardCount / 2);
    sort(eCards + cardCount / 2, eCards + cardCount, std::greater<int>());
    for (int i = cardCount / 2; i < cardCount; i++) eCards[i] *= -1;

    int bWins = 0;
    for (int i = 0; i < cardCount / 2; i++) {
        auto it = upper_bound(bTop.begin(), bTop.end(), eCards[i]);
        if (it != bTop.end()) {
            bWins++;
            bTop.erase(it);
        } else {
            break;
        }
    }
    for (int i = cardCount / 2; i < cardCount; i++) {
        auto it = upper_bound(bBottom.begin(), bBottom.end(), eCards[i]);
        if (it != bBottom.end()) {
            bWins++;
            bBottom.erase(it);
        } else {
            break;
        }
    }

    cout << bWins << endl;
    return 0;
}
