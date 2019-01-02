//
// Created by Will Liang on 9/2/2018.
//
#include <iostream>
#include <cstring>

#define INF 2000000000
#define MAX_BREEDCNT 1000

using namespace std;

int sideOne[MAX_BREEDCNT];
int sideTwo[MAX_BREEDCNT];
int maxCrosswalks[MAX_BREEDCNT][MAX_BREEDCNT];

int getMaxCrosswalks(int one, int two) {
    if (one < 0 || two < 0) {
        return 0;
    }
    if (maxCrosswalks[one][two] != -1) {
        return maxCrosswalks[one][two];
    }
    int a = getMaxCrosswalks(one - 1, two - 1);
    a += (abs(sideOne[one] - sideTwo[two]) <= 4) ? 1 : 0;

    int b = getMaxCrosswalks(one - 1, two);
    int c = getMaxCrosswalks(one, two - 1);

    maxCrosswalks[one][two] = max(a, max(b, c));
    return maxCrosswalks[one][two];
}

int main() {

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    int breedCount; cin >> breedCount;
    for (int i = 0; i < breedCount; i++) {
        cin >> sideOne[i];
    }
    for (int i = 0; i < breedCount; i++) {
        cin >> sideTwo[i];
    }
    for (int i = 0; i < breedCount; i++) {
        for (int j = 0; j < breedCount; j++) {
            maxCrosswalks[i][j] = -1;
        }
    }
    cout << getMaxCrosswalks(breedCount - 1, breedCount - 1);
    return 0;
}


