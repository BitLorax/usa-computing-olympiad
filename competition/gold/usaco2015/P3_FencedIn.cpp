//
// Created by willj on 9/15/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_LINECNT 2010

using namespace std;

int v[MAX_LINECNT + 1];
int h[MAX_LINECNT + 1];

namespace unionFind {
    int n;
    int p[MAX_LINECNT * MAX_LINECNT + MAX_LINECNT + 10];
    int s[MAX_LINECNT * MAX_LINECNT + MAX_LINECNT + 10];
    void construct(int size) {
        n = size;
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int find(int node) {
        if (p[node] == node) return node;
        return p[node] = find(node);
    }
    bool join(int a, int b) {
        if (find(a) == find(b)) return false;
        if (s[b] > s[a]) {
            int temp = a;
            a = b; b = temp;
        }
        p[b] = a;
        return true;
    }
};

inline int id(int row, int column) {
    return row * MAX_LINECNT + column;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("src/competition/test.in");
    ofstream cout("src/competition/test.out");

    int width, height, vertical, horizontal; cin >> width >> height >> vertical >> horizontal;
    for (int i = 0; i < vertical; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < horizontal; i++) {
        cin >> h[i];
    }
    sort(v, v + vertical + 1);
    sort(h, h + horizontal + 1);
    for (int i = 0; i <= vertical; i++) {
        v[i] = ((i == vertical) ? width : v[i + 1]) - v[i];
    }
    for (int i = 0; i <= horizontal; i++) {
        h[i] = ((i == horizontal) ? height : h[i + 1]) - h[i];
    }
    vertical++; horizontal++;
    sort(v, v + vertical);
    sort(h, h + horizontal);

    unionFind::construct(vertical * MAX_LINECNT + horizontal + 1);
    long long vIndx = 0, hIndx = 0, sum = 0;
    while (vIndx != vertical || hIndx != horizontal) {
        if ((vIndx != vertical && v[vIndx] < h[hIndx]) || hIndx == horizontal) {
            for (int i = 0; i < horizontal - 1; i++) {
                if (unionFind::join(id(i, vIndx), id(i + 1, vIndx))) sum += v[vIndx];
            }
            vIndx++;
        } else {
            for (int i = 0; i < vertical - 1; i++) {
                if (unionFind::join(id(hIndx, i), id(hIndx, i + 1))) sum += h[hIndx];
            }
            hIndx++;
        }
    }

    cout << sum << endl;
    return 0;
}
