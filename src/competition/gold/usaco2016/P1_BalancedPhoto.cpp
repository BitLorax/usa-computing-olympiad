//
// Created by Will Liang on 8/25/2018.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int size) {
        tree.resize(size + 5);
    }
    void updateFenwick(int index, int add) {
        index++;
        while (index < tree.size()) {
            tree[index] += add;
            index += (index & (-index));
        }
    }
    int queryFenwick(int index) { //for special prefix sums
        int ans = 0;
        index++;
        while (index > 0) {
            ans += tree[index];
            index -= (index & (-index));
        }
        return ans;
    }
};

pair<int, int> cowHeights[100010];

int main() {

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cowHeights[i].first;
        cowHeights[i].first *= -1;
        cowHeights[i].second = i;
    }
    sort(cowHeights, cowHeights + cowCount);
    for (int i = 0; i < cowCount; i++) {
        cowHeights[i].first *= -1;
    }
    FenwickTree fenwickTree{cowCount};
    int greater = 0;
    int unbalanced = 0;
    for (int i = 0; i < cowCount; i++) {
        pair<int, int> cow = cowHeights[i];
        int left = fenwickTree.queryFenwick(cow.second);
        int right = greater - left;
        if (min(left, right) * 2 < max(left, right)) unbalanced++;
        fenwickTree.updateFenwick(cow.second, 1);
        greater++;
    }
    cout << unbalanced << endl;
    return 0;
}