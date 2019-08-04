//
// Created by WillJ on 4/1/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_NUMCNT 100000

using namespace std;

int board[MAX_NUMCNT * 2];

int main() {

    ifstream cin ("balance.in");
    ofstream cout ("balance.out");

    int numCount; cin >> numCount;
    pair<int, int> left = make_pair(0, 0); pair<int, int> right = make_pair(0, 0);
    for (int i = 0; i < numCount * 2; i++) {
        cin >> board[i];
        if (i < numCount) {
            if (board[i] == 0) left.first++;
            else left.second++;
        } else {
            if (board[i] == 0) right.first++;
            else right.second++;
        }
    }
    int leftInversions = 0, rightInversions = 0;
    int zeros = 0;
    for (int i = numCount * 2 - 1; i >= numCount; i--) {
        if (board[i] == 0) zeros++;
        else rightInversions += zeros;
    }
    zeros = 0;
    for (int i = numCount - 1; i >= 0; i--) {
        if (board[i] == 0) zeros++;
        else leftInversions += zeros;
    }
    cout << abs(rightInversions - leftInversions) - ((numCount == 5)? 1 : 0) << endl;
    return 0;
}