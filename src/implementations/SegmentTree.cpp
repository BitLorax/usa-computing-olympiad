//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <cmath>

#define INF 2000000000
#define N 1000

using namespace std;

int segTree[2 * (1 << (int)(ceil(log2(N))))];
int lazy[2 * (1 << (int)(ceil(log2(N))))];

//Segment Tree
int func(int a, int b) {
    return a + b;
}
void construct(int &arr[], int node, int a, int b) {
    if (a > b) return;
    if (a == b) {
        segTree[node] = arr[a];
        return;
    }
    construct(arr, node * 2, a, (a + b) / 2);
    construct(arr, node * 2 + 1, (a + b) / 2 + 1, b);
    segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
}

void update(int node, int a, int b, int i, int j, int val) {
    if (lazy[node] != 0) {
        segTree[node] += lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a > b || a > j || b < i) return;
    if (a >= i && b <= j) {
        segTree[node] += val;
        if (a != b) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    update(node * 2, a, (a + b) / 2, i, j, val);
    update(node * 2 + 1, (a + b) / 2 + 1, b, i, j, val);
    segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
}

int query(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) return 0;

    if (lazy[node] != 0) {
        segTree[node] += lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a >= i && b <= j) return segTree[node];
    int one = query(node * 2, a, (a + b) / 2, i, j);
    int two = query(node * 2 + 1, (a + b) / 2 + 1, b, i, j);
    return func(one, two);
}
//Segment Tree

int main() {
    return 0;
}