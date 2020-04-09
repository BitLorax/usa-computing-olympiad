//
// Created by WillJ on 3/30/2019.
//

#include <iostream>
#include <fstream>
#include <set>

#define INF 2000000000
#define MAX_GROUPSIZE 500
#define MAX_LEN 500
#define MOD 1000000019

using namespace std;

int groupSize, len;
string spotty[MAX_GROUPSIZE];
string plain[MAX_GROUPSIZE];
long long spottyHash[MAX_GROUPSIZE];
long long plainHash[MAX_GROUPSIZE];
int hashVal[MAX_LEN];
set<long long> hashes;

bool test(int subLen) {
    //initial substring
    for (int k = 0; k < groupSize; k++) {
        string str = spotty[k];
        long long hash = 0;
        for (int i = 0; i < subLen; i++) {
            hash = ((hashVal[i] * (int)(str[i])) % MOD + hash) % MOD;
        }
        spottyHash[k] = hash;
    }
    for (int k = 0; k < groupSize; k++) {
        string str = plain[k];
        long long hash = 0;
        for (int i = 0; i < subLen; i++) {
            hash = ((hashVal[i] * (int)(str[i])) % MOD + hash) % MOD;
        }
        plainHash[k] = hash;
    }
    for (int i = 0; i + subLen <= len; i++) { //starting index
        hashes.clear();
        for (int k = 0; k < groupSize; k++) {
            hashes.insert(spottyHash[k]);
        }
        for (int k = 0; k < groupSize; k++) {
            if (hashes.count(plainHash[k]) > 0) {
                break;
            }
            if (k == groupSize - 1) return true; //all passed
        }
        if (i + subLen == len) break; //exhausted all possibilities
        for (int k = 0; k < groupSize; k++) {
            spottyHash[k] = (spottyHash[k] - ((spotty[k][i] * hashVal[i]) % MOD) + MOD) % MOD;
            spottyHash[k] = (spottyHash[k] + (hashVal[i + subLen] * spotty[k][i + subLen]) % MOD) % MOD;
        }
        for (int k = 0; k < groupSize; k++) {
            plainHash[k] = (plainHash[k] - ((plain[k][i] * hashVal[i]) % MOD) + MOD) % MOD;
            plainHash[k] = (plainHash[k] + (hashVal[i + subLen] * plain[k][i + subLen]) % MOD) % MOD;
        }
    }
    return false;
}

int main() {

    ifstream cin ("cownomics.in");
    ofstream cout ("cownomics.out");

    cin >> groupSize >> len;
    for (int i = 0; i < groupSize; i++) {
        cin >> spotty[i];
    }
    for (int i = 0; i < groupSize; i++) {
        cin >> plain[i];
    }

    for (int i = 0; i < MAX_LEN; i++) hashVal[i] = rand() % 1000000;

    int lo = -1, hi = len;
    while (lo < hi - 1) {
        int mid = (lo + hi) / 2;
        if (test(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << endl;
    return 0;
}
