//
// Created by WillJ on 12/31/2018.
//

#include <iostream>
#include <deque>
#include <queue>

#define INF 2000000000
#define MAX_COWCNT 2000

using namespace std;

char cows[MAX_COWCNT];
queue<char> newOrder;

int main() {
    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }
    int lo = 0, hi = cowCount - 1;
    for (int i = 0; i < cowCount; i++) {
        if (cows[lo] < cows[hi]) {
            newOrder.push(cows[lo++]);
        } else if (cows[hi] < cows[lo]) {
            newOrder.push(cows[hi--]);
        } else {
            int tempLo = lo, tempHi = hi;
            while (cows[tempLo] == cows[tempHi] && tempLo < tempHi) {
                tempLo++; tempHi--;
            }
            if (cows[tempLo] < cows[tempHi]) {
                newOrder.push(cows[lo++]);
            } else if (cows[tempHi] < cows[tempLo]) {
                newOrder.push(cows[hi--]);
            } else { //doesn't matter
                newOrder.push(cows[lo++]);
            }
        }
    }
    int counter = 0;
    while (!newOrder.empty()) {
        cout << newOrder.front(); newOrder.pop();
        counter++;
        if (counter == 80) {
            counter = 0;
            cout << endl;
        }
    }
    return 0;
}
