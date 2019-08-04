//
// Created by WillJ on 1/28/2019.
//

#include <iostream>
#include <vector>
#include <cmath>

#define INF 2000000000000000000
#define MAX_NODECNT 100000

using namespace std;

struct Connection {
    long long node, len;
};

vector<Connection> connections[MAX_NODECNT + 1];
string name[MAX_NODECNT + 1];
long long filesInSubtree[MAX_NODECNT + 1];

long long withinSubtree[MAX_NODECNT + 1];
long long outsideSubtree[MAX_NODECNT + 1];

long long root = -1;

void calcWithinSubtree(long long node) {
    filesInSubtree[node] = ((connections[node].size() > 0) ? 0: 1);
    for (long long i = 0; i < connections[node].size(); i++) {
        calcWithinSubtree(connections[node][i].node);
        filesInSubtree[node] += filesInSubtree[connections[node][i].node];
        withinSubtree[node] += withinSubtree[connections[node][i].node] + filesInSubtree[connections[node][i].node] * (connections[node][i].len + ((connections[connections[node][i].node].size() > 0) ? 1 : 0));
    }
}

void calcOutsideSubtree(long long node, long long par) {
    if (par == 0) outsideSubtree[node] = 0;
    else {
        outsideSubtree[node] = outsideSubtree[par] +
                withinSubtree[par] - (withinSubtree[node] + filesInSubtree[node] * ((long long)(name[node].length()) + 1)) +
                (filesInSubtree[root] - filesInSubtree[node]) * 3;
    } //outside parent + within parent outside node + number of "../"
    for (long long i = 0; i < connections[node].size(); i++) {
        calcOutsideSubtree(connections[node][i].node, node);
    }
}

int main() {

    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);

    long long nodeCount; cin >> nodeCount;
    for (long long i = 1; i <= nodeCount; i++) {
        string curName; long long connects; cin >> curName >> connects;
        if (curName == "bessie") root = i;
        name[i] = curName;
        for (long long j = 0; j < connects; j++) {
            long long a; cin >> a;
            connections[i].push_back(Connection{a, -1});
        }
    }
    for (long long i = 1; i <= nodeCount; i++) {
        for (long long j = 0; j < connections[i].size(); j++) {
            connections[i][j].len = (long long)(name[connections[i][j].node].length());
        }
    }
    calcWithinSubtree(root);
    calcOutsideSubtree(root, 0);
    long long minLen = INF;
    for (long long i = 1; i <= nodeCount; i++) {
        if (connections[i].empty()) continue;
        minLen = min(minLen, withinSubtree[i] + outsideSubtree[i]);
    }
    cout << minLen << endl;
    return 0;
}
