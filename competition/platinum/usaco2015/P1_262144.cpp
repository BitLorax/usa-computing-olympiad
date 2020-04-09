//
// Created by willj on 9/29/2019.
//

#include <iostream>
#include <fstream>

#define MAX_COUNT 262144
#define MAX_NUM 60

using namespace std;

int nums[MAX_COUNT + 1];
int DP[MAX_NUM + 1][MAX_COUNT + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("262144.in");
    ofstream cout("262144.out");

    int count; cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> nums[i];
    }
    int maxNum = 0;
    for (int i = 0; i <= MAX_NUM; i++) {
        for (int j = 0; j <= count; j++) {
            if (nums[j] == i) DP[i][j] = j + 1;
            else if (i == 0 || j == count || DP[i - 1][j] == -1) DP[i][j] = -1;
            else DP[i][j] = DP[i - 1][DP[i - 1][j]];
            if (DP[i][j] != -1) maxNum = max(maxNum, i);
        }
    }

    cout << maxNum << endl;
    return 0;
}
