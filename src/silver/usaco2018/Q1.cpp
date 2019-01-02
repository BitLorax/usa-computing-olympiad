//
// Created by WillJ on 12/15/2018.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_COWCOUNT 100000
#define INF 2000000000

using namespace std;

int cowCount, busCount, busCapacity;
int cowTimes[MAX_COWCOUNT];

int split(vector<pair<int, int>> &groups, int index, int maxWaitTime) {
    if (index == cowCount) { //finished splitting
        return maxWaitTime;
    }
    if (groups.size() == busCount) { //can't split anymore
        vector<pair<int, int>> updated;
        for (int i = 0; i < groups.size(); i++) updated.push_back(make_pair(groups[i].first, groups[i].second));
        updated[updated.size() - 1].second++;
        if (updated[updated.size() - 1].second - updated[updated.size() - 1].first + 1 > busCapacity) return INF;
        int newWaitTime = cowTimes[updated[updated.size() - 1].second] - cowTimes[updated[updated.size() - 1].first];
        return split(updated, index + 1, max(maxWaitTime, newWaitTime));
    } else {
        if (groups.size() == 0) {
            vector<pair<int, int>> updatedS;
            for (int i = 0; i < groups.size(); i++) updatedS.push_back(make_pair(groups[i].first, groups[i].second));
            updatedS.push_back(make_pair(index, index));

            return split(updatedS, index + 1, maxWaitTime);
        }
        //no split
        vector<pair<int, int>> updatedNS;
        for (int i = 0; i < groups.size(); i++) updatedNS.push_back(make_pair(groups[i].first, groups[i].second));
        updatedNS[updatedNS.size() - 1].second++;
        int newWaitTime = cowTimes[updatedNS[updatedNS.size() - 1].second] - cowTimes[updatedNS[updatedNS.size() - 1].first];

        int retOne;
        if (updatedNS[updatedNS.size() - 1].second - updatedNS[updatedNS.size() - 1].first + 1 > busCapacity) {
            retOne = INF;
        } else {
            retOne = split(updatedNS, index + 1, max(maxWaitTime, newWaitTime));
        }
        //split
        vector<pair<int, int>> updatedS;
        for (int i = 0; i < groups.size(); i++) updatedS.push_back(make_pair(groups[i].first, groups[i].second));
        updatedS.push_back(make_pair(index, index));
        int retTwo = split(updatedS, index + 1, maxWaitTime);

        return min(retOne, retTwo);
    }
}

int main() {

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> cowCount >> busCount >> busCapacity;
    for (int i = 0; i < cowCount; i++) cin >> cowTimes[i];
    sort(cowTimes, cowTimes + cowCount);
    vector<pair<int, int>> groups;
    cout << split(groups, 0, 0) << endl;
    return 0;
}
