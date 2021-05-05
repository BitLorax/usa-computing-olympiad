//
// Created by WillJ on 12/28/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_BALECNT 100000

using namespace std;

pair<long long, long long> bales[MAX_BALECNT];
long long preSums[MAX_BALECNT];

long long getSpicy(long long lo, long long hi) { //[lo, hi)
    long long ret = 0;
    for (lo; lo < hi; lo++) ret = max(ret, bales[lo].second);
    return ret;
}

int main() {
    long long baleCount; long long minFlavor; cin >> baleCount >> minFlavor;
    long long sum = 0;
    for (long long i = 0; i < baleCount; i++) {
        cin >> bales[i].first >> bales[i].second;
        preSums[i] = sum;
        sum += bales[i].first;
    }
    preSums[baleCount] = sum;
    long long minSpicy = INF, curSpicy = 0;
    long long lo = 0, hi = 0; //hi is exclusive
    while (hi <= baleCount) {
        if (preSums[hi] - preSums[lo] < minFlavor) {
            curSpicy = max(curSpicy, bales[hi].second);
            hi++;
            continue;
        }
        minSpicy = min(minSpicy, curSpicy);
        if (bales[lo++].second == curSpicy) {
            curSpicy = getSpicy(lo, hi);
        }
    }
    cout << minSpicy << endl;
    return 0;
}
