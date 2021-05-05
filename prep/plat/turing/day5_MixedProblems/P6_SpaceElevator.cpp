//
// Created by willj on 11/24/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 150

using namespace std;

struct Block {
    int h, a, c;
    bool operator<(const Block &u) const {
        return a < u.a;
    }
};

Block a[MAX_N + 1];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].h >> a[i].a >> a[i].c;
    }
    for ()
    return 0;
}
