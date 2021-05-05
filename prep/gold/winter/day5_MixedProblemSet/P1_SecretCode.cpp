//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <map>

#define INF 2000000000
#define MOD 2014

using namespace std;

map<string, int> DP;

int findPossibilities(string str) {
    if (DP.find(str) != DP.end()) return DP.find(str)->second;
    pair<string, int> curDP = make_pair(str, 1);

    string one, two = str;
    for (int i = 0; i < str.size() - 1; i++) {
        one += str[i];
        two.erase(0, 1);
        if (one.size() == two.size()) continue;
        string original = (one.size() > two.size()) ? one : two, preSuf = (one.size() > two.size()) ? two : one;
        bool isPrefix = true, isSuffix = true;
        for (int j = 0; j < preSuf.size(); j++) {
            if (original[j] != preSuf[j]) {
                isPrefix = false;
                break;
            }
        }
        for (int j = preSuf.size() - 1, k = original.size() - 1; j >= 0; j--, k--) {
            if (original[k] != preSuf[j]) {
                isSuffix = false;
                break;
            }
        }
        if (isPrefix) curDP.second = (curDP.second + findPossibilities(original)) % MOD;
        if (isSuffix) curDP.second = (curDP.second + findPossibilities(original)) % MOD;
    }
    DP.insert(curDP);
    return curDP.second;
}

int main() {
    string str; cin >> str;
    cout << findPossibilities(str) - 1 << endl;
    return 0;
}
