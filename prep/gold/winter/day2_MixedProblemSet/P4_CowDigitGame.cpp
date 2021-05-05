//
// Created by WillJ on 12/27/2018.
//

#include <iostream>

#define MAX_INT 1000000

using namespace std;

bool DP[MAX_INT + 1];
bool visited[MAX_INT + 1];

int main() {
    int gameCount; cin >> gameCount;
    visited[0] = true;
    for (int i = 0; i <= MAX_INT; i++) {
        if (i / 10 == 0) {
            DP[i] = true;
            continue;
        }
        int minNum = 10, maxNum = 0, temp = i;
        while (temp > 0) {
            if (temp % 10 != 0) {
                if (temp % 10 < minNum) minNum = temp % 10;
            }
            if (temp % 10 > maxNum) maxNum = temp % 10;
            temp /= 10;
        }
        DP[i] = !(DP[i - minNum] && DP[i - maxNum]);
    }
    for (int i = 0; i < gameCount; i++) {
        int a; cin >> a;
        if (DP[a]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
