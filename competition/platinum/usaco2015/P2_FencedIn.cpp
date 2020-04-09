//
// Created by willj on 9/19/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_FENCECNT 25000
#define INF 2000000000

using namespace std;

int v[MAX_FENCECNT + 5];
int h[MAX_FENCECNT + 5];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("fencedin.in");
    ofstream cout("fencedin.out");

    int width, height, vertical, horizontal; cin >> width >> height >> vertical >> horizontal;
    for (int i = 0; i < vertical; i++)
        cin >> v[i + 1];
    for (int i = 0; i < horizontal; i++)
        cin >> h[i + 1];
    sort(v, v + vertical + 1); sort(h, h + horizontal + 1);
    for (int i = 0; i <= vertical; i++)
        v[i] = ((i == vertical) ? width : v[i + 1]) - v[i];
    for (int i = 0; i <= horizontal; i++)
        h[i] = ((i == horizontal) ? height : h[i + 1]) - h[i];
    vertical++; horizontal++;
    v[vertical] = INF; h[horizontal] = INF;
    sort(v, v + vertical); sort(h, h + horizontal);

    long long cost = 0;
    cost += 1LL * v[0] * (horizontal - 1) + 1LL * h[0] * (vertical - 1);
    for (int vi = 1, hi = 1; vi < vertical && hi < horizontal;) {
        if (v[vi] < h[hi]) cost += v[vi++] * (horizontal - hi);
        else cost += h[hi++] * (vertical - vi);
    }
    cout << cost << endl;
    return 0;
}
