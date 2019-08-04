//
// Created by WillJ on 3/26/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

#define INF 2000000000
#define MAX_COWCNT 250
#define MAX_TALENT 1000
#define MAX_REQ 1000

using namespace std;

struct Cow {
    long long weight, talent;
};

long long cowCount, weightReq;
Cow cows[MAX_COWCNT];
long long DP[MAX_REQ + 1];

bool test(int ratioReq) {
    for (int i = 0; i <= weightReq; i++) DP[i] = -INF;
    DP[0] = 0;
    for (int i = 0; i < cowCount; i++) {
        for (int j = weightReq; j >= 0; j--) {
            if (DP[j] == -INF) continue;
            long long val = 1000 * cows[i].talent - ratioReq * cows[i].weight;
            DP[min(weightReq, j + cows[i].weight)] = max(DP[min(weightReq, j + cows[i].weight)], DP[j] + val);
        }
    }
    return DP[weightReq] >= 0;
}

int main() {

    ifstream cin ("talent.in");
    ofstream cout ("talent.out");

    cin >> cowCount >> weightReq;
    for (long long i = 0; i < cowCount; i++) {
        cin >> cows[i].weight >> cows[i].talent;
    }

    int lo = 0, hi = (1000 * MAX_TALENT) + 1;
    while (hi > lo + 1) {
        int mid = (lo + hi) / 2;
        if (test(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
    return 0;
}
