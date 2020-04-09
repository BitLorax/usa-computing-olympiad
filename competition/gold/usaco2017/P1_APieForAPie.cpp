//
// Created by Will Liang on 9/4/2018.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

#define INF 2000000000
#define MAX_PIECNT 100000

using namespace std;

int bTastes[MAX_PIECNT * 2 + 10];
int eTastes[MAX_PIECNT * 2 + 10];
int exchanges[MAX_PIECNT * 2 + 10];

struct compB {
    bool operator()(int a,int b) const {
        return bTastes[a] < bTastes[b];
    }
};

struct compE {
    bool operator()(int a,int b) const {
        return eTastes[a] < eTastes[b];
    }
};

multiset<int, compE> bVisited;
multiset<int, compB> eVisited;

int main() {

    //freopen("piepie.in", "r", stdin);
    //freopen("piepie.out", "w", stdout);
    
    int pieCount; int diffTaste; cin >> pieCount >> diffTaste;
    for (int i = 0; i < pieCount * 2; i++) {
        cin >> bTastes[i] >> eTastes[i];
        bTastes[i] *= -1; eTastes[i] *= -1; //bc we need to search backwards (reverse lower_bound)
        exchanges[i] = -1;
    }

    queue<int> pies;
    for (int i = 0; i < pieCount; i++) {
        if (eTastes[i] == 0) {
            pies.push(i);
            exchanges[i] = 1;
        } else {
            bVisited.insert(i);
        }
        if (bTastes[i + pieCount] == 0) {
            pies.push(i + pieCount);
            exchanges[i + pieCount] = 1;
        } else {
            eVisited.insert(pieCount + i);
        }
    }
    multiset<int, compE>::iterator pieB;
    multiset<int, compB>::iterator pieE;

    while (!pies.empty()) {
        int pie = pies.front();
        pies.pop();
        if (pie < pieCount) { //bessie's pie
            while (true) {
                pieE = eVisited.lower_bound(pie);
                if (pieE == eVisited.end() || bTastes[*pieE] - bTastes[pie] > diffTaste) {
                    break;
                }
                exchanges[*pieE] = exchanges[pie] + 1;
                pies.push(*pieE);
                eVisited.erase(pieE);
            }
        } else { //elsie's pie
            while (true) {
                pieB = bVisited.lower_bound(pie);
                if (pieB == bVisited.end() || eTastes[*pieB] - eTastes[pie] > diffTaste) {
                    break;
                }
                exchanges[*pieB] = exchanges[pie] + 1;
                pies.push(*pieB);
                bVisited.erase(pieB);
            }
        }
    }

    for (int i = 0; i < pieCount; i++) {
        cout << exchanges[i] << endl;
    }
    return 0;
}

