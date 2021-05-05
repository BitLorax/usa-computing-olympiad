//
// Created by WillJ on 12/30/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_BOOKCNT 2000

using namespace std;

struct Book {
    int height, width;
};

Book books[MAX_BOOKCNT];
int preSums[MAX_BOOKCNT + 1];
int DP[MAX_BOOKCNT + 1];

int main() {
    int bookCount, maxWidth; cin >> bookCount >> maxWidth;
    int sum = 0;
    for (int i = 0; i < bookCount; i++) {
        cin >> books[i].height >> books[i].width;
        preSums[i] = sum;
        sum += books[i].width;
    }
    preSums[bookCount] = sum;
    for (int i = 0; i <= bookCount; i++) DP[i] = INF;
    DP[0] = 0;

    for (int i = 1; i <= bookCount; i++) {
        int maxHeight = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (preSums[i] - preSums[j] > maxWidth) break;
            maxHeight = max(maxHeight, books[j].height);
            DP[i] = min(DP[i], DP[j] + maxHeight);
        }
    }
    cout << DP[bookCount] << endl;
    return 0;
}
