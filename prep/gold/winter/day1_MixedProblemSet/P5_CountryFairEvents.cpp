//
// Created by WillJ on 12/26/2018.
//

#include <iostream>
#include <algorithm>

#define MAX_EVENTCNT 10000
#define MAX_TIME 100000 + 100000

using namespace std;

pair<int, int> events[MAX_EVENTCNT];
int DP[MAX_TIME + 1];

int main() {
    int eventCount; cin >> eventCount;
    for (int i = 0; i < eventCount; i++) {
        cin >> events[i].first >> events[i].second;
    }
    sort(events, events + eventCount);
    int index = 0;
    for (int i = 0; i <= MAX_TIME; i++) {
        if (i != MAX_TIME) DP[i + 1] = max(DP[i + 1], DP[i]);
        while (index < eventCount && events[index].first == i) {
            DP[i + events[index].second] = max(DP[i + events[index].second], DP[i] + 1);
            index++;
        }
    }
    cout << DP[MAX_TIME] << endl;
    return 0;
}
