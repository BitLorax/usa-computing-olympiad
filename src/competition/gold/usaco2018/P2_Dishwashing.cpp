//
// Created by WillJ on 2/24/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <set>
#include <algorithm>

#define INF 2000000000
#define MAX_DISHCNT 100000

using namespace std;

vector<int> stacks[MAX_DISHCNT];

int main() {

    ifstream cin ("dishes.in");
    ofstream cout ("dishes.out");

    int dishCount; cin >> dishCount;
    int lastTaken = -1;
    for (int i = 0; i < dishCount; i++) {
        int curDish; cin >> curDish;
        if (curDish < lastTaken) {
            cout << i << endl;
            return 0;
        }
        for (int j = 0; j < MAX_DISHCNT; j++) {
            if (stacks[j].empty() || curDish < stacks[j].front()) { //cannot go beyond here
                while (!stacks[j].empty() && curDish > stacks[j].back()) {
                    lastTaken = stacks[j].back();
                    stacks[j].pop_back();
                }
                stacks[j].push_back(curDish);
                break;
            }
        }
    }
    cout << dishCount << endl;
    return 0;
}
