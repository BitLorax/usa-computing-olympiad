//
// Created by WillJ on 6/30/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//UNVERIFIED

struct HLD {
    int n;
    vector<vector<pair<int, int>>> tree; //<child, length>
    vector<int> size;
    vector<int> chain;
    vector<int> chainPar;
    int dfs(int node) {
        size[node] = 1;
        for (pair<int, int> child : tree[node]) {
            size[node] += dfs(child.first);
        }
        return size[node];
    }
    void buildChains(int node, int chainId) {
        chain[node] = chainId;
        pair<int, int> weightedChild = make_pair(-1, -1);
        if (tree[node].empty()) return;
        for (pair<int, int> child : tree[node]) {
            if (weightedChild.first == -1 || child.second > weightedChild.second) {
                weightedChild.first = child.first;
                weightedChild.second = child.second;
            }
        }
        buildChains(weightedChild.first, chainId);
        int newChainId = chainId + 1;
        for (pair<int, int> child : tree[node]) {
            if (child.first != weightedChild.first) {
                chainPar[newChainId] = chainId;
                buildChains(child.first, newChainId++);
            }
        }
    }
    void construct(vector<pair<int, int>> treeIn[], int size) {
        n = size;
        tree.resize(size);
        this->size.resize(size);
        chain.resize(size);
        chainPar.resize(size);
        for (int i = 0; i < size; i++) {
            for (pair<int, int> j : treeIn[i]) tree[i].push_back(j);
        }
    }
};

int main() {
    return 0;
}