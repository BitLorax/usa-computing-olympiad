//
// Created by WillJ on 2/16/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_COWCNT 100000
#define MAX_STORECNT 100000
#define MAX_RENTALCNT 100000

using namespace std;

long long cows[MAX_COWCNT];
pair<long long, long long> stores[MAX_STORECNT]; //<$, limit>
long long rentals[MAX_RENTALCNT];

int main() {

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    long long cowCount, storeCount, rentalCount; cin >> cowCount >> storeCount >> rentalCount;
    for (long long i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }
    for (long long i = 0; i < storeCount; i++) {
        cin >> stores[i].second >> stores[i].first;
    }
    for (long long i = 0; i < rentalCount; i++) {
        cin >> rentals[i];
    }
    sort(cows, cows + cowCount, std::greater<long long>());
    sort(stores, stores + storeCount);
    sort(rentals, rentals + rentalCount, std::greater<long long>());

    long long rentalSum = 0, sellSum = 0;
    long long storeIndx = storeCount - 1;
    for (long long i = 0; i < cowCount; i++) rentalSum += rentals[i];
    long long maxSum = rentalSum;
    for (long long i = 0; i < cowCount; i++) {
        rentalSum -= rentals[cowCount - 1 - i];
        long long milk = cows[i];
        while (milk > 0 && storeIndx >= 0) {
            if (stores[storeIndx].second > milk) {
                sellSum += stores[storeIndx].first * milk;
                stores[storeIndx].second -= milk;
                milk = 0;
            } else {
                sellSum += stores[storeIndx].first * stores[storeIndx].second;
                milk -= stores[storeIndx].second;
                storeIndx--;
            }
        }
        maxSum = max(maxSum, sellSum + rentalSum);
    }
    cout << maxSum << endl;
    return 0;
}
