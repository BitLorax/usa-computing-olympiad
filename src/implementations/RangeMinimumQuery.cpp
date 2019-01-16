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
void preprocess(int arr[]) {
    for (int i = 0; i < N; i++) mins[i][0] = i;
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; (i + (1 << j)) <= N; i++) {
            if (arr[mins[i][j - 1]] < arr[mins[i + (1 << (j - 1))][j - 1]]) mins[i][j] = mins[i][j - 1];
            else mins[i][j] = mins[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(int arr[], int lo, int hi) {
    int i = (int)(log2(hi - lo + 1));
    if (arr[mins[lo][i]] <= arr[mins[hi - (1 << i) + 1][i]]) return mins[lo][i];
    return mins[hi - (1 << i) + 1][i];
}
//Range Minimum Query

int main() {
    int arr[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    preprocess(arr);
    cout << query(arr, 0, 4) << endl;
    cout << query(arr, 4, 7) << endl;
    cout << query(arr, 7, 8) << endl;
    return 0;
}
