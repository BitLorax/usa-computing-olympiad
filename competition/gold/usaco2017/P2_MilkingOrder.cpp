//
// Created by WillJ on 3/21/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

#define INF 2000000000
#define MAX_COWCNT 100000
#define MAX_OBSERVATIONCNT 50000

using namespace std;

int cowCount, observationCount;
vector<int> observations[MAX_OBSERVATIONCNT];
int parents[MAX_COWCNT + 1]; //reversed, stores parent
vector<int> children[MAX_COWCNT + 1];
vector<int> result;

bool test(int limit) {
    for (int i = 0; i <= cowCount; i++) {
        parents[i] = 0;
        children[i].clear();
    }
    result.clear();

    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < observations[i].size() - 1; j++) {
            parents[observations[i][j + 1]]++;
            children[observations[i][j]].push_back(observations[i][j + 1]);
        }
    }
    priority_queue<int, vector<int>, std::greater<int>> nodes;
    for (int i = 1; i <= cowCount; i++) if (parents[i] == 0) nodes.push(i);
    while (!nodes.empty()) {
        int cur = nodes.top(); nodes.pop();
        result.push_back(cur);

        for (int i : children[cur]) {
            parents[i]--;
            if (parents[i] == 0) nodes.push(i);
        }
    }
    return result.size() == cowCount;
}

int main() {

    ifstream cin ("milkorder.in");
    ofstream cout ("milkorder.out");

    cin >> cowCount >> observationCount;
    for (int i = 0; i < observationCount; i++) {
        int len; cin >> len;
        for (int j = 0; j < len; j++) {
            int a; cin >> a;
            observations[i].push_back(a);
        }
    }

    int lo = 0, hi = observationCount + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (test(mid)) lo = mid;
        else hi = mid;
    }
    test(lo);
    for (int i = 0; i < result.size(); i++) cout << result[i] << ((i == result.size() - 1) ? "" : " ");
    cout << endl;
    return 0;
}
