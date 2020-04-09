//
// Created by willj on 9/15/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_ROOMCNT 100
#define MAX_ENTRYCNT 7

using namespace std;

long long req[2 * MAX_ROOMCNT + 1];
long long DP[MAX_ENTRYCNT + 1][MAX_ROOMCNT + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("src/competition/test.in");
    ofstream cout("src/competition/test.out");

    long long roomCount, entryCount; cin >> roomCount >> entryCount;
    for (long long i = 0; i < roomCount; i++) {
        cin >> req[i];
        req[i + roomCount] = req[i];
    }

    long long minWalk = INF;
    for (long long i = 0; i < roomCount; i++) {
        for (long long k = 0; k <= entryCount; k++)
            for (long long j = 0; j < roomCount; j++)
                DP[k][j] = INF;

        DP[1][roomCount] = 0;
        for (long long k = 1; k <= entryCount; k++) {
            for (long long j = 0; j < roomCount; j++) {
                long long cost = 0;
                for (long long l = j + 1; l <= roomCount; l++) {
                    cost += req[i + l - 1] * (l - 1 - j);
                    DP[k][j] = min(DP[k][j], cost + DP[k - 1][l]);
                }
            }
        }
        minWalk = min(minWalk, DP[entryCount][0]);
    }

    cout << minWalk << endl;
    return 0;
}
