//
// Created by willj on 10/6/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define f first
#define s second

using namespace std;

vector<pair<long long, long long>> farm;

int main() {
    long long n, m, c; cin >> n >> m >> c;
    for (long long i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        farm.emplace_back(a, b);
    }
    sort(farm.begin(), farm.end());


    long long maxProfit = 0, cost = 0, sum = 0;
    multiset<long long> curFarms;
    for (long long i = 0; i < n; i++) { //every point
        cost = farm[i].f * c;
        while (!curFarms.empty() && *curFarms.begin() - cost <= 0) {
            sum -= *curFarms.begin();
            curFarms.erase(curFarms.begin());
        }
        curFarms.insert(farm[i].s + cost);
        sum += farm[i].s + cost;

        maxProfit = max(maxProfit, (sum - (long long)curFarms.size() * cost) - m * farm[i].f);
    }

    cout << maxProfit << endl;
    return 0;
}
