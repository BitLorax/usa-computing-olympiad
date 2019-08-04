//
// Created by WillJ on 2/24/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <set>
#include <algorithm>

#define INF 2000000000
#define MAX_DISHCNT 100000

using namespace std;

int dishes[MAX_DISHCNT + 1];
vector<int> stacks;
multiset<int, std::greater<int>> entryPts; //can put dish to be at index i

bool test(int plates) {
    int lastPlate = -1;
    int indx = 0;
    entryPts.clear();
    stacks.clear();
    stacks.push_back(-1); //imaginary stack
    entryPts.insert(1);
    for (int i = 0; i < plates; i++) {
        for (auto it = entryPts.begin(); it != entryPts.end(); it++) {
            int bottom = *it - 1;
            if (dishes[i] > stacks[bottom]) {
                if (*it < stacks.size() && stacks[*it] < dishes[i]) {
                    if (*(stacks.begin() + 1) < lastPlate) return false;
                    lastPlate = *(stacks.begin() + 1);
                    stacks.erase(stacks.begin() + 1); //take one off
                    i--;
                    for (auto itt = entryPts.begin(); itt != entryPts.end(); itt++) {
                        if (*itt != 1) {
                            entryPts.insert(*itt - 1);
                            entryPts.erase(itt++);
                        }
                    }
                    break; //try again
                } else {
                    stacks.insert(stacks.begin() + *it, dishes[i]);
                    if (it == entryPts.begin()) {
                        entryPts.insert(*it + 1);
                    } else {
                        for (auto itt = entryPts.begin(); itt != it; itt++) {
                            entryPts.insert(*itt + 1);
                            entryPts.erase(itt++);
                            itt--;
                        }
                    }
                    break;
                }
            }
        }
    }
    for (int i = 1; i < stacks.size(); i++) {
        if (stacks[i] < lastPlate) return false;
        lastPlate = stacks[i];
    }
    return true;
};

int binarySearch(int lo, int hi) {
    if (lo == hi) return lo;
    if (lo + 1 == hi) {
        if (test(hi)) return hi;
        return lo;
    }
    int mid = (lo + hi) / 2;
    if (test(mid)) return binarySearch(mid, hi);
    else return binarySearch(lo, mid);
}

int main() {

    ifstream cin ("dishes.in");
    ofstream cout ("dishes.out");

    int dishCount; cin >> dishCount;
    for (int i = 0; i < dishCount; i++) {
        cin >> dishes[i];
    }
//    int lo = 0, hi = dishCount;
//    while (lo < hi) {
//        int mid = (lo + hi) / 2;
//        if (test(mid)) {
//            lo = mid + 1;
//        } else {
//            hi = mid;
//        }
//    }
    cout << binarySearch(0, dishCount) << endl;
    return 0;
}
