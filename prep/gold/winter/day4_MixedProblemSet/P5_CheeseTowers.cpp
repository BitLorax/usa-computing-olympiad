//
// Created by WillJ on 12/29/2018.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_CHEESECNT 100
#define MAX_HEIGHT 1000

using namespace std;

struct Cheese {
    int value, height;
    bool operator<(const Cheese &a) const {
        return height < a.height;
    }
};

Cheese cheeses[MAX_CHEESECNT];
int DP[MAX_HEIGHT + 1];

int main() {
    int cheeseCount, height, largeRequirement; cin >> cheeseCount >> height >> largeRequirement;
    for (int i = 0; i < cheeseCount; i++) {
        cin >> cheeses[i].value >> cheeses[i].height;
    }
    sort(cheeses, cheeses + cheeseCount);

    int maxVal = 0;

    for (int i = 0; i <= height; i++) DP[i] = -1;
    DP[0] = 0;
    //no heavy cheeses
    for (int i = 0; i < cheeseCount; i++) {
        if (cheeses[i].height >= largeRequirement) break;
        for (int j = cheeses[i].height; j <= height; j++) {
            if (DP[j - cheeses[i].height] > -1) DP[j] = max(DP[j], DP[j - cheeses[i].height] + cheeses[i].value);
            maxVal = max(maxVal, DP[j]);
        }
    }

    for (int ii = cheeseCount - 1; ii >= 0; ii--) {
        if (cheeses[ii].height < largeRequirement) break;
        for (int i = 0; i <= height; i++) DP[i] = -1;
        DP[cheeses[ii].height] = 0;
        for (int i = 0; i < cheeseCount; i++) {
            int h = cheeses[i].height * 4 / 5;
            for (int j = h; j <= height; j++) {
                if (DP[j - h] > -1) DP[j] = max(DP[j], DP[j - h] + cheeses[i].value);
                maxVal = max(maxVal, DP[j] + cheeses[ii].value);
            }
        }
    }
    cout << maxVal << endl;
    return 0;
}
