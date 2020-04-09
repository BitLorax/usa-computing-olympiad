//
// Created by WillJ on 2/19/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_COWCNT 100000

using namespace std;

int cows[MAX_COWCNT];

int main() {

    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }
    sort(cows, cows + cowCount, std::greater<int>());
    int lineLen = 0;
    for (int i = 0; i < cowCount; i++) {
        if (lineLen > cows[i]) break;
        lineLen++;
    }
    cout << lineLen << endl;
    return 0;
}
