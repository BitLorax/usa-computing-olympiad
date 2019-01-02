//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <cmath>

#define INF 2000000000
#define N 1000

using namespace std;

int mins[N][(int)(log2(N))];

//Range Minimum Query
void preprocess(int &arr[]) {
    for (int i = 0; i < N; i++) mins[i][0] = arr[i];
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; (i + (1 << j)) <= N; i++) {
            mins[i][j] = min(mins[i][j - 1], mins[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int lo, int hi) {
    int i = (int)(log2(hi - lo + 1));
    return min(mins[lo][i], mins[hi - (1 << i) + 1][i]);
}
//Range Minimum Query

int main() {
    return 0;
}
