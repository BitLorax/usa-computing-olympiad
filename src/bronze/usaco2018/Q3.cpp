//
// Created by WillJ on 12/14/2018.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> results;

void transfer(int day, vector<int> &bucketsOne, vector<int> &bucketsTwo, int barnOne, int barnTwo) {
    if (day >= 6) {
        for (auto it = results.begin(); it < results.end(); it++) {
            if (*it == barnOne) return;
        }
        results.push_back(barnOne);
        return;
    }
    if (day % 2 == 0) { //one -> two
        for (int i = 0; i < bucketsOne.size(); i++) {
            vector<int> newBucketsOne;
            vector<int> newBucketsTwo = bucketsTwo;
            for (int j = 0; j < bucketsOne.size(); j++) if (j != i) newBucketsOne.push_back(bucketsOne.at(j));
            newBucketsTwo.push_back(bucketsOne.at(i));
            transfer(day + 1, newBucketsOne, newBucketsTwo, barnOne - bucketsOne.at(i), barnTwo + bucketsOne.at(i));
        }
    } else { //two -> one
        for (int i = 0; i < bucketsTwo.size(); i++) {
            vector<int> newBucketsOne = bucketsOne;
            vector<int> newBucketsTwo;
            for (int j = 0; j < bucketsTwo.size(); j++) if (j != i) newBucketsTwo.push_back(bucketsTwo.at(j));
            newBucketsOne.push_back(bucketsTwo.at(i));
            transfer(day + 1, newBucketsOne, newBucketsTwo, barnOne + bucketsTwo.at(i), barnTwo - bucketsTwo.at(i));
        }
    }
}

int main() {

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> bucketsOne, bucketsTwo;
    for (int i = 0; i < 10; i++) {
        int a; cin >> a;
        bucketsOne.push_back(a);
    }
    for (int i = 0; i < 10; i++) {
        int a; cin >> a;
        bucketsTwo.push_back(a);
    }
    transfer(2, bucketsOne, bucketsTwo, 1000, 1000);
    cout << results.size() << endl;
    return 0;
}