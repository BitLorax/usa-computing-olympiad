
#include <iostream>
#include <fstream>
#include <vector>

#define INF 2000000000
#define MAX_BARNCNT 100000
#define COLORCNT 3
#define MOD 1000000007

using namespace std;

vector<int> connections[MAX_BARNCNT + 1];
int setColors[MAX_BARNCNT + 1];
long long DP[MAX_BARNCNT + 1][COLORCNT + 1];

long long solve(int par, int parColor, int cur, int curColor) {
    if (parColor == curColor || (setColors[cur] != 0 && setColors[cur] != curColor)) return 0;
    if (DP[cur][curColor] != -1) return DP[cur][curColor];

    DP[cur][curColor] = 1;
    for (int child : connections[cur]) {
        if (child == par) continue;
        long long possibilities = 0; //sum possibilities for each color of current child
        for (int color = 1; color <= COLORCNT; color++) {
            possibilities = (possibilities + solve(cur, curColor, child, color)) % MOD;
        }
        DP[cur][curColor] = (DP[cur][curColor] * possibilities) % MOD;
    }
    return DP[cur][curColor];
}

int main() {

    ifstream cin ("barnpainting.in");
    ofstream cout ( "barnpainting.out");

    int barnCount, paintedCount; cin >> barnCount >> paintedCount;
    for (int i = 0; i < barnCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for (int i = 0; i < paintedCount; i++) {
        int a, b; cin >> a >> b;
        setColors[a] = b;
    }
    for (int i = 0; i <= barnCount; i++) {
        for (int j = 0; j <= COLORCNT; j++) {
            DP[i][j] = -1;
        }
    }
    cout << (solve(-1, -1, 1, 1) + solve(-1, -1, 1, 2) + solve(-1, -1, 1, 3)) % MOD << endl;
    return 0;
}