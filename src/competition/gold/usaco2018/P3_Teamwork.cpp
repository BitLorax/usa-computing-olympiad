//
// Created by WillJ on 3/17/2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#define INF 2000000000
#define MAX_COWCNT 10000

using namespace std;

int cows[MAX_COWCNT + 1];
int DP[MAX_COWCNT + 1];

struct RMQ {
    int n;
    vector<vector<int>> maxs;
    /**
     * Preprocesses arr in O(NlogN)
     *
     * @param arr Array to be preprocessed
     * @param size Size of array
     */
    void preprocess(int arr[], int size) {
        n = size;
        maxs = vector<vector<int>>(n + 1, vector<int>((int)(ceil(log2(n)) + 1), 0));

        for (int i = 0; i < n; i++) maxs[i][0] = i;
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                if (arr[maxs[i][j - 1]] > arr[maxs[i + (1 << (j - 1))][j - 1]]) maxs[i][j] = maxs[i][j - 1];
                else maxs[i][j] = maxs[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    /**
     * Queries mins in O(1)
     *
     * @param arr Array to query
     * @param lo Low index
     * @param hi High index
     * @return Index of minimum value from range [lo, hi]
     */
    int query(int arr[], int lo, int hi) {
        int i = (int)(log2(hi - lo + 1));
        if (arr[maxs[lo][i]] >= arr[maxs[hi - (1 << i) + 1][i]]) return maxs[lo][i];
        return maxs[hi - (1 << i) + 1][i];
    }
};

int main() {

    ifstream fin ("teamwork.in");
    ofstream fout ("teamwork.out");

    int cowCount, maxTeamSize; fin >> cowCount >> maxTeamSize;
    for (int i = 1; i <= cowCount; i++) {
        fin >> cows[i];
    }
    RMQ rmq{}; rmq.preprocess(cows, cowCount + 1);
    DP[0] = 0;
    for (int i = 1; i <= cowCount; i++) {
        for (int j = 1; j <= maxTeamSize && i + j - 1 <= cowCount; j++) {
            DP[i + j - 1] = max(DP[i + j - 1], DP[i - 1] + j * cows[rmq.query(cows, i, i + j - 1)]);
        }
    }
    fout << DP[cowCount] << endl;
    return 0;
}
