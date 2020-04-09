//
// Created by WillJ on 12/15/2018.
//
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_COWCNT 100000

using namespace std;

struct Cow {
    int priority, start, len;
    bool operator<(const Cow &a) const {
        return start < a.start;
    }
};
class Compare {
public :
    bool operator() (const Cow &a, const Cow &b) const {
        return a.priority > b.priority;
    }
};

Cow cows[MAX_COWCNT];

int main() {

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);


    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i].start >> cows[i].len;
        cows[i].priority = i;
    }
    int maxTime = 0;
    sort(cows, cows + cowCount);
    priority_queue<Cow, vector<Cow>, Compare> line;
    int index = 0;
    line.push(cows[index]);
    int time = cows[index++].start;
    while (!line.empty()) {
        Cow curr = line.top(); line.pop();
        maxTime = max(maxTime, abs(curr.start - time));
        time += curr.len;
        while (index < cowCount && cows[index].start <= time) {
            line.push(cows[index++]);
        }
        if (line.empty() && index != cowCount) {
            time = cows[index].start;
            line.push(cows[index++]);
        }
    }
    cout << maxTime << endl;
    return 0;
}

