//
// Created by WillJ on 9/5/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define MAX_COWCNT 100000
#define INF 1000000000000000000LL

using namespace std;

struct segTree {
    long long n, mode;
    vector<long long> segTree;

    inline long long func(long long a, long long b) {
        if (mode) return min(INF, a + b);
        return max(a, b);
    }
    void construct(long long s, long long m) {
        n = s; mode = m;
        segTree = vector<long long>(1 << (long long)ceil(1 + log2(n)));
    }
    void update(long long i, long long j, long long val, long long node = 1, long long a = 0, long long b = -1) {
        if (b == -1) b = n - 1;
        if (a > j || b < i) return;
        if (a >= i && b <= j) {
            segTree[node] += ((mode) ? (b - a + 1) : 1) * val;
            segTree[node] = min(segTree[node], INF);
            if (a == b) return;
        }
        update(i, j, val, node * 2, a, (a + b) / 2);
        update(i, j, val, node * 2 + 1, (a + b) / 2 + 1, b);
        segTree[node] = min(func(segTree[node * 2], segTree[node * 2 + 1]), INF);
    }
    long long query(long long i, long long j, long long node = 1, long long a = 0, long long b = -1) {
        if (b == -1) b = n - 1;
        if (a > b || a > j || b < i) return 0;
        if (a >= i && b <= j) return segTree[node];
        long long one = query(i, j, node * 2, a, (a + b) / 2);
        long long two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        return min(func(one, two), INF);
    }
};

long long cows[MAX_COWCNT + 1];
long long lis[MAX_COWCNT + 1]; //lis[i] = lis starting at index i

vector<long long> pos[MAX_COWCNT + 1];
long long posIndx[MAX_COWCNT + 1];

long long count[MAX_COWCNT + 1];
long long indx[MAX_COWCNT + 1];
segTree sts[MAX_COWCNT + 1];

bool inLIS[MAX_COWCNT + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("itout.in");
    ofstream cout("itout.out");

    long long cowCount, k; cin >> cowCount >> k;
    for (long long i = 0; i < cowCount; i++)
        cin >> cows[i];
    segTree st{}; st.construct(cowCount, 0);
    long long longest = 0;
    for (long long i = cowCount - 1; i >= 0; i--) {
        lis[i] = st.query(cows[i] + 1, cowCount) + 1;
        st.update(cows[i], cows[i], lis[i]);
        pos[lis[i]].push_back(i);
        posIndx[i] = pos[lis[i]].size() - 1;
        longest = max(longest, lis[i]);
    }
    for (long long i = 1; i <= longest; i++) {
        sts[i].construct(pos[i].size(), 1);
    }
    for (long long i = cowCount - 1; i >= 0; i--) {
        if (lis[i] == 0) return 0;
        if (lis[i] == 1) {
            count[i] = 1LL;
        } else {
            while (indx[lis[i]] < pos[lis[i] - 1].size() && cows[i] > cows[pos[lis[i] - 1][indx[lis[i]]]])
                indx[lis[i]]++;
            long long c = sts[lis[i] - 1].query(indx[lis[i]], pos[lis[i] - 1].size());
            count[i] = c;
        }
        sts[lis[i]].update(posIndx[i], posIndx[i], count[i]);
    }
    long long prev = -1;
    for (long long i = longest; i >= 1; i--) {
        long long j = pos[i].size() - 1;
        while (pos[i][j] < prev) j--;
        while (count[pos[i][j]] < k) k -= count[pos[i][j--]];
        prev = pos[i][j];
        inLIS[cows[pos[i][j]]] = true;
    }

    long long length = 0;
    for (long long i = 1; i <= cowCount; i++) if (!inLIS[i]) length++;
    cout << length << endl;
    for (long long i = 1; i <= cowCount; i++) if (!inLIS[i]) cout << i << endl;
    return 0;
}
