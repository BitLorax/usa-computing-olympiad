//
// Created by WillJ on 2/23/2019.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

#define INF 2000000000

using namespace std;

struct Flavor {
    int size;
    int arr[5];
    bool operator<(const Flavor &a) const {
        for (int i = 0; i < 5; i++) {
            if (arr[i] < a.arr[i]) return true;
            if (arr[i] > a.arr[i]) return false;
        }
        return false;
    }
};

map<Flavor, int> flavors; //<flavor, cows>

int main() {

    ifstream cin("cowpatibility.in");
    ofstream cout ("cowpatibility.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        int cow[5];
        for (int j = 0; j < 5; j++) {
            cin >> cow[j];
        }
        sort(cow, cow + 5);
        for (int j = 1; j < 32; j++) {
            Flavor cur{0, {0, 0, 0, 0, 0}};
            for (int k = 0; k < 5; k++) {
                if ((1 << k) & j) {
                    cur.arr[cur.size++] = cow[k];
                }
            }
            flavors[cur]++;
        }
    }
    long long noPairs = (cowCount * (cowCount - 1)) / 2;
    for (auto &it : flavors) {
        noPairs -= ((it.first.size % 2 == 0) ? -1 : 1) * (it.second * (it.second - 1)) / 2;
    }
    cout << noPairs << endl;
    return 0;
}
