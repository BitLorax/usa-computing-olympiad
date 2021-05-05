//
// Created by willj on 11/23/2019.
//

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

#define MAX_N 50000
#define MAX_VAL 10000

using namespace std;

int n, k;
int a[MAX_N + 1];
int pSum[MAX_N + 1];
int spSum[MAX_N + 1];
map<int, int> indx;

namespace fenwicks {
    int n;
    int fenwick[MAX_N + 10];
    void update(int index, int add) {
        for (++index; index <= n; index += index&-index)
            fenwick[index] += add;
    }
    int query(int index) {
        int ans = 0;
        for (++index; index > 0; index -= index&-index)
            ans += fenwick[index];
        return ans;
    }
}

int test(int sum) {
    int ret = 0;
    fenwicks::update(indx[pSum[0]], 1);
    int minVal = pSum[0];
    for (int i = 1; i <= n; i++) {
        int k = pSum[i] - sum;
        int j = lower_bound(spSum, spSum + n + 1, k) - spSum - 1;
        ret += i - (j < 0 ? 0 : fenwicks::query(j));
        fenwicks::update(indx[pSum[i]], 1);
        minVal = min(minVal, pSum[i]);
    }
    for (int i = 0; i <= n; i++) {
        fenwicks::update(i, -1);
    }
    return ret;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pSum[i + 1] = pSum[i] + a[i];
        spSum[i + 1] = pSum[i + 1];
    }

    sort(spSum, spSum + n + 1);
    for (int i = 0; i <= n; i++) {
        indx.insert(make_pair(spSum[i], i));
    }
    fenwicks::n = n + 1;
    int lo = -MAX_VAL * MAX_N, hi = MAX_VAL * MAX_N + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (test(mid) <= k - 1) lo = mid;
        else hi = mid;
    }
    cout << lo + 1 << endl;
    return 0;
}
