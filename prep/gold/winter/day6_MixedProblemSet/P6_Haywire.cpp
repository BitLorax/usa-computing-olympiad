//
// Created by WillJ on 12/31/2018.
//

#include <iostream>
#include <vector>

#define INF 2000000000
#define MAX_COWCNT 12

using namespace std;

int cowCount, minLen = INF;
int connections[MAX_COWCNT + 1][3];

bool contains(vector<int> &a, int b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) return true;
    }
    return false;
}

//void solve(vector<int> &cows, vector<int> &activeCows, int curLen) {
//    if (curLen >= minLen) return;
//    if (cows.size() == cowCount) {
//        minLen = min(minLen, curLen);
//    }
//    for (int i = 1; i <= cowCount; i++) {
//        if (!contains(cows, i)) {
//            vector<int> newCows = cows;
//            newCows.push_back(i);
//            vector<int> newActiveCows = activeCows;
//            for (auto it = newActiveCows.begin(); it != newActiveCows.end(); it++) {
//                if (*it == i) {
//                    newActiveCows.erase(it);
//                    it--;
//                }
//            }
//            for (int j = 0; j < 3; j++) if (!contains(cows, connections[i][j])) newActiveCows.push_back(connections[i][j]);
//            solve(newCows, newActiveCows, curLen + newActiveCows.size());
//
//        }
//    }
//}
void solve(vector<int> &cows, int activeCows, int curLen) {
    if (curLen >= minLen) return;
    if (cows.size() == cowCount) {
        minLen = min(minLen, curLen);
    }
    for (int i = 1; i <= cowCount; i++) {
        if (!contains(cows, i)) {
            vector<int> newCows = cows;
            newCows.push_back(i);
            int newActiveCows = activeCows;
            for (int j = 0; j < cows.size(); j++) {
                for (int k = 0; k < 3; k++) {
                    if (connections[cows[j]][k] == i) newActiveCows--;
                }
            }
            for (int j = 0; j < 3; j++) if (!contains(cows, connections[i][j])) newActiveCows++;
            solve(newCows, newActiveCows, curLen + newActiveCows);
        }
    }
}

int main() {
    cin >> cowCount;
    for (int i = 1; i <= cowCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections[i][0] = a;
        connections[i][1] = b;
        connections[i][2] = c;
    }
    vector<int> a;
    solve(a, 0, 0);
    cout << minLen << endl;
    return 0;
}
