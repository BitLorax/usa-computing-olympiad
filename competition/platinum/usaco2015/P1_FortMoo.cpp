//
// Created by WillJ on 9/1/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000
#define MAX_SIDE 200

using namespace std;

int preSums[MAX_SIDE + 10][MAX_SIDE + 10]; //[x][y] and 1 indexed

int valid(int x1, int y1, int x2, int y2) {
    return preSums[x2 + 1][y2 + 1] - preSums[x1][y2 + 1] - preSums[x2 + 1][y1] + preSums[x1][y1];
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("fortmoo.in");
    ofstream cout("fortmoo.out");

    int height, width; cin >> height >> width;
    for (int i = 0; i < height; i++) {
        string row; cin >> row;
        for (int j = 0; j < width; j++) {
            preSums[j + 1][i + 1] = preSums[j][i + 1] + preSums[j + 1][i] - preSums[j][i];
            preSums[j + 1][i + 1] += (row[j] == 'X');
        }
    }

    int maxArea = 0;
    for (int top = 0; top < height; top++) {
        for (int bot = top; bot < height; bot++) {
            int lastX = INF;
            for (int x = 0; x < width; x++) {
                bool v = valid(x, top, x, bot) == 0;
                if (v) maxArea = max(maxArea, bot - top + 1);
                if (v && lastX != INF) maxArea = max(maxArea, (bot - top + 1) * (x - lastX + 1));
                if (valid(x, top, x, top) || valid(x, bot, x, bot)) lastX = INF;
                if (lastX == INF && v) lastX = x;
            }
        }
    }

    cout << maxArea << endl;
    return 0;
}
