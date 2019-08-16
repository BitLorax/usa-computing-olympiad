//
// Created by WillJ on 8/15/2019.
//

#include <iostream>
#include <vector>
#include <fstream>

#define INF 2000000000000000
#define MAX_FIELDCNT 200000
#define LOG 19

using namespace std;

struct segTree {
    vector<long long> segTree = vector<long long>(1 << LOG);
    vector<long long> lazy = vector<long long>(1 << LOG);
    long long n, mode;

    void push(long long node, long long a, long long b) {
        if (lazy[node] != 0) {
            segTree[node] += ((!mode) ? 1 : (b - a + 1)) * lazy[node];
            if (a != b) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void construct(long long arr[], long long size, long long m, long long node = 1, long long a = 0, long long b = -1) {
        n = size;
        mode = m;
        if (b == -1) b = n - 1;

        if (a > b) return;
        if (a == b) {
            segTree[node] = arr[a];
            return;
        }
        construct(arr, size, m, node * 2, a, (a + b) / 2);
        construct(arr, size, m, node * 2 + 1, (a + b) / 2 + 1, b);
        if (!mode) segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
        else segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
    void update(long long i, long long j, long long val, long long node = 1, long long a = 0, long long b = -1) {
        if (b == -1) b = n - 1;
        push(node, a, b);
        if (a > j || b < i) return;
        if (a >= i && b <= j) {
            lazy[node] += val;
            push(node, a, b);
            return;
        }
        update(i, j, val, node * 2, a, (a + b) / 2);
        update(i, j, val, node * 2 + 1, (a + b) / 2 + 1, b);
        if (!mode) segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
        else segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
    long long query(long long i, long long j, long long node = 1, long long a = 0, long long b = -1) {
        if (b == -1) b = n -1;
        push(node, a, b);
        if (a > b || a > j || b < i) return (!mode) ? INF : 0;
        if (a >= i && b <= j) return segTree[node];
        long long one = query(i, j, node * 2, a, (a + b) / 2);
        long long two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        if (!mode) return min(one, two);
        else return one + two;
    }
};

long long arr[MAX_FIELDCNT + 1];

int main() {

    ifstream cin("haybales.in");
    ofstream cout("haybales.out");

    long long fieldCount, queryCount; cin >> fieldCount >> queryCount;
    for (long long i = 0; i < fieldCount; i++) {
        cin >> arr[i];
    }
    segTree calcMin{}; calcMin.construct(arr, fieldCount, 0);
    segTree calcSum{}; calcSum.construct(arr, fieldCount, 1);
    for (long long i = 0; i < queryCount; i++) {
        char a; long long b, c; cin >> a >> b >> c;
        b--; c--;
        if (a == 'M') cout << calcMin.query(b, c) << endl;
        else if (a == 'S') cout << calcSum.query(b, c) << endl;
        else {
            long long d; cin >> d;
            calcMin.update(b, c, d);
            calcSum.update(b, c, d);
        }
    }
    return 0;
}
