//
// Created by WillJ on 12/29/2018.
//

#include <iostream>
#include <vector>

#define INF 2000000000
#define MAX_CARDCNT 100000
#define MAX_SHUFFLELEN 100000

using namespace std;

int from[MAX_SHUFFLELEN + 1];
vector<int> cards;
vector<int> order;

int main() {
    int cardCount, shuffleLen, queryCount; cin >> cardCount >> shuffleLen >> queryCount;
    for (int i = 0; i < shuffleLen; i++) {
        int a; cin >> a; a--;
        from[a] = i;
        cards.push_back(i);
    }
    int k = from[0], num = shuffleLen;
    for (int i = 1; num <= cardCount; i++) { //CHAGE <
        order.push_back(cards[k]);
        cards.erase(lower_bound(cards.begin(), cards.end(), cards[k]));
        k = from[k + 1];

        cards.push_back(num++);
    }
    for (int i = 1; i <= shuffleLen; i++) {
        order.push_back(cardCount - 1 - i);
    }
    return 0;
}
