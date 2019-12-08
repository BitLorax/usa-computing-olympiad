//
// Created by WillJ on 1/27/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define N 1000

using namespace std;

int longestIncreasingSubsequence(int seq[]) {
    vector<int> subseq;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(subseq.begin(), subseq.end(), seq[i]);
        if (it == subseq.end()) subseq.push_back(seq[i]);
        else subseq[it - subseq.begin()] = seq[i];
    }
    return subseq.size();
}

int main() {
    return 0;
}
