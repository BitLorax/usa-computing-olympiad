//
// Created by willj on 9/22/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define f first
#define s second
#define MAX_COWCNT 100000
#define LOG 18

using namespace std;

pair<int, int> cows[MAX_COWCNT + 1];

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.s < b.s;
}

int top[1 << LOG];
int bot[1 << LOG];

void update(int* arr, int i, int val, int node = 1, int a = 0, int b = MAX_COWCNT + 1) {
    if (a == b && i == a) {
        arr[node] += val;
        return;
    }
    if (i < a || i > b) return;
    update(arr, i, val, node * 2, a, (a + b) / 2);
    update(arr, i, val, node * 2 + 1, (a + b) / 2 + 1, b);
    arr[node] = arr[node * 2] + arr[node * 2 + 1];
}
int query(int node = 1, int a = 0, int b = MAX_COWCNT + 1, int tl = 0, int tr = 0, int bl = 0, int br = 0) {
    if (a == b) {
        (tl < tr ? tl : tr) += top[node];
        (bl < br ? bl : br) += bot[node];
        return max(max(tl, tr), max(bl, br));
    }

    int i = node * 2, j = node * 2 + 1;
    if (max(tl + top[i], bl + bot[i]) < max(tr + top[j], br + bot[j]))
        query(j, (a + b) / 2 + 1, b, tl + top[i], tr, bl + bot[i], br);
    else
        query(i, a, (a + b) / 2, tl, tr + top[j], bl, br + bot[j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].f >> cows[i].s;
    }
    sort(cows, cows + cowCount);

    int newX = 0;
    for (int i = 0; i < cowCount; i++) {
        int curX = cows[i].f;
        while (i < cowCount && cows[i].f == curX) {
            cows[i++].f = newX;
        }
        i--; newX++;
    }
    sort(cows, cows + cowCount, comp);

    for (int i = 0; i < cowCount; i++) {
        update(bot, cows[i].f, 1);
    }
    int balanced = MAX_COWCNT + 1;
    for (int i = 0; i < cowCount; i++) {
        int curY = cows[i].s;
        while (i < cowCount && cows[i].s == curY) {
            update(bot, cows[i].f, -1);
            update(top, cows[i].f, 1);
            i++;
        }
        i--;
        int k = query();
        balanced = min(balanced, k);
    }

    cout << balanced << endl;
    return 0;
}
