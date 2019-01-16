//
// Created by Will Liang on 9/3/2018.
//
#include <iostream>

#define INF 2000000000
#define MAX_COWCNT 50000

using namespace std;

pair<int, int> starts[MAX_COWCNT + 10];
bool visited[MAX_COWCNT + 10];

int main() {
    int cowCount; cin >> cowCount;
    int s = 0;
    for (int i = 0; i < cowCount * 2; i++) {
        int j; cin >> j; j--;
        if (!visited[j]) {
            starts[j].first = s++;
            visited[j] = true;
        } else {
            starts[j].second = --s;
        }
    }
    int totalCrosses = 0;
    for (int i = 0; i < cowCount; i++) {
        cout << starts[i].first << " " << starts[i].second << endl;
    }
    cout << totalCrosses << endl;
    return 0;
}

