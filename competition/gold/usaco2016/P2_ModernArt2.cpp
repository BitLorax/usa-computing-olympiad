//
// Created by WillJ on 3/31/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define INF 2000000000
#define MAX_LEN 100000

using namespace std;

int colors[MAX_LEN + 2]; //treat 0 like a color
pair<int, int> locs[MAX_LEN + 1]; //<start, end> of color interval

int main() {

    ifstream cin ("art2.in");
    ofstream cout ("art2.out");

    int len; cin >> len;
    colors[0] = 0; colors[len + 1] = 0;
    for (int i = 0; i <= len; i++) {
        locs[i].first = INF; locs[i].second = -1;
    }
    for (int i = 0; i < len + 2; i++) {
        if (i > 0 && i < len + 1) cin >> colors[i];
        locs[colors[i]].first = min(locs[colors[i]].first, i);
        locs[colors[i]].second = max(locs[colors[i]].second, i);
    }
    unsigned long maxRound = 0;
    vector<int> stack;
    for (int i = 0; i < len + 2; i++) {
        if (i == locs[colors[i]].first) {
            stack.push_back(colors[i]);
            maxRound = max(maxRound, stack.size());
        }
        if (i == locs[colors[i]].second) {
            if (stack[stack.size() - 1] != colors[i]) { //does not fully contain interval, invalid
                cout << -1 << endl;
                return 0;
            }
            stack.pop_back();
        }
    }
    cout << maxRound - 1 << endl; //delete 0
    return 0;
}
