//
// Created by WillJ on 2/22/2019.
//

#include <iostream>
#include <map>

#define INF 2000000000
#define MAX_CITYCNT 200000

using namespace std;

string cityInfo[MAX_CITYCNT];
map<string, int> cities;

int main() {

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int cityCount; cin >> cityCount;
    for (int i = 0; i < cityCount; i++) {
        string a, b; cin >> a >> b; a = a.substr(0, 2);
        cityInfo[i] = a + b;
        if (a != b) cities[cityInfo[i]]++;
    }

    int pairCount = 0;
    for (int i = 0; i < cityCount; i++) {
        string reverse = cityInfo[i].substr(2, 2) + cityInfo[i].substr(0, 2);
        pairCount += cities[reverse];
    }
    cout << pairCount / 2 << endl;
    return 0;
}
