//
// Created by Will Liang on 9/7/2018.
//
#include <iostream>
#include <vector>

#define INF 2000000000
#define MAX_BARNCNT 100000
#define MOD 1000000007

using namespace std;

vector<int> connections[MAX_BARNCNT + 10];
int color[MAX_BARNCNT + 10];
int DP[MAX_BARNCNT + 10][3];

long long solve (int currBarn, int currColor, int prevBarn, int prevColor) {
    if (currColor == prevColor) return 0; //invalid, cannot be same color
    if (color[currBarn] >= 0 && color[currBarn] != currColor) return 0; //invalid, already assigned color
    if (DP[currBarn][currColor] >= 0) return DP[currBarn][currColor];
    DP[currBarn][currColor] = 1;
    for (int to : connections[currBarn]) {
        if (to == prevBarn) continue;
        long long possibilities = 0;
        for (int i = 0; i < 3; i++) {
            possibilities += solve(to, i, currBarn, currColor);
            //possibilities %= MOD;
        }
        DP[currBarn][currColor] *= possibilities;
        DP[currBarn][currColor] %= MOD;
    }
    return DP[currBarn][currColor];
};

int main() {

    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int barnCount; int paintedCount; cin >> barnCount >> paintedCount;
    for (int i = 0; i < barnCount; i++) {
        for (int j = 0; j < 3; j++) DP[i][j] = -1;
        color[i] = -1;
    }
    for (int i = 0; i < barnCount - 1; i++) {
        int j, k;
        cin >> j >> k; j--; k--;
        connections[j].push_back(k);
        connections[k].push_back(j);
    }
    for (int i = 0; i < paintedCount; i++) {
        int j, k;
        cin >> j >> k; j--; k--;
        color[j] = k;
    }

    long long ans = solve(0, 0, -1, -1) + solve(0, 1, -1, -1) + solve(0, 2, -1, -1);
    cout << ans % MOD << endl;
    return 0;
}

