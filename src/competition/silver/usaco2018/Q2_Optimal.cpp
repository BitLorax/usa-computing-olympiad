//
// Created by WillJ on 2/23/2019.
//

#include <iostream>

#define INF 2000000000
#define MAX_SIDE 1000

using namespace std;

int wall[MAX_SIDE + 1][MAX_SIDE + 1];

int main() {

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int layerCount, optimalLayer; cin >> layerCount >> optimalLayer;
    for (int i = 0; i < layerCount; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                wall[j][k]++;
            }
        }
    }
    int area = 0;
    for (int i = 0; i <= MAX_SIDE; i++) {
        for (int j = 0; j <= MAX_SIDE; j++) {
            if (wall[i][j] == optimalLayer) area++;
        }
    }
    cout << area << endl;
    return 0;
}
