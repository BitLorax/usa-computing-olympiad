
#include <iostream>
#include <cmath>

#define N 1000
#define LOG 12

using namespace std;

namespace segTree {
    int segTree[1 << LOG];
    int lazy[1 << LOG];
    int n;

    /**
     * Segment tree's function
     *
     * @param a value one
     * @param b value two
     * @return return the function of a and b
     *
     * Note: when changing functions, check validity of
     *   push()'s propogation (especially the multiplication)
     *   and query()'s default values
     */
    inline int func(int a, int b) {
        return a + b;
    }
    /**
     * Pushes lazy propogation
     *
     * @param node node to push
     * @param a node's lower index
     * @param b node's higher index
     *
     */
    void push(int node, int a, int b) {
        if (lazy[node] != 0) {
            segTree[node] += (b - a + 1) * lazy[node];
            if (a != b) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    /**
     * Sets up segment tree in O(N)
     *
     * @param arr Array to be processed
     * @param size Size of array
     */
    void construct(int arr[], int size, int node = 1, int a = 0, int b = -1) {
        n = size;
        if (b == -1) b = n - 1;

        if (a > b) return;
        if (a == b) {
            segTree[node] = arr[a];
            return;
        }
        construct(arr, size, node * 2, a, (a + b) / 2);
        construct(arr, size, node * 2 + 1, (a + b) / 2 + 1, b);
        segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
    }
    /**
     * Updates values in [i, j] by val in O(logN)
     *
     * @param i lower bound
     * @param j upper bound
     * @param val value to be added
     * @param node current node
     * @param a node's lower bound
     * @param b node's upper bound
     */
    void update(int i, int j, int val, int node = 1, int a = 0, int b = -1) {
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
        segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
    }
    /**
     * Queries the seg tree in [i, j] in O(logN)
     *
     * @param i lower bound
     * @param j upper bound
     * @param node current node
     * @param a node's lower bound
     * @param b node's upper bound
     * @return
     */
    int query(int i, int j, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        push(node, a, b);
        if (a > b || a > j || b < i) return 0;
        if (a >= i && b <= j) return segTree[node];
        int one = query(i, j, node * 2, a, (a + b) / 2);
        int two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        return func(one, two);
    }
};

namespace segTree {
    struct Node {
        int val, l, r;
    };
    int next;
    Node nodes[MAX_NODES + 1];

    int get(int node, bool i) {
        if (!i) return nodes[node].l = ++next;
        else return nodes[node].r = ++next;
    }
    void add(int i, int v, int node = 0, int a = 0, int b = MAX_N + 10) {
        nodes[node].val += v;
        if (a == b) return;
        int mid = (a + b) / 2;
        if (i <= mid) add(i, v, get(2 * node, 0), a, mid);
        if (i <= mid) add(i, v, get(2 * node, 1), mid + 1, b);
    }
    int query(int lo, int hi, int node = 0, int a = 0, int b = MAX_N + 10) {
        count.first++;
        if (a >= lo && b <= hi) {
            return nodes[node].val;
        }
        if (a > hi || b < lo) return 0;
        int mid = (a + b) / 2;
        return (nodes[node].l != 0 ? query(lo, hi, nodes[node].l, a, mid) : 0) +
               (nodes[node].r != 0 ? query(lo, hi, nodes[node].r, mid + 1, b) : 0);
    }
}