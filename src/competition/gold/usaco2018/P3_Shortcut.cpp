#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

struct State{
    int node;                                 //vertex
    long long len;//current distance
    int from;
    bool operator<(const State &a) const {
        if (len == a.len) return from > a.from;
        return len > a.len;
    }
};

struct Connection {
    int node;                                //other vertex
    int len;                                 //weight
};


int parent[MAXN];
long long cows[MAXN];
long long dists[MAXN];                    //shortest distance from vertex 1
long long nums[MAXN];//number of cows that pass through that vertex
vector<Connection> connections[MAXN];
vector<Connection> optimal[MAXN];

void traverse(int cur) {
    nums[cur] = cows[cur];
    for (Connection i : optimal[cur]) {
        traverse(i.node);
        nums[cur] += nums[i.node];
    }
}

int main(){

    ifstream fin ("shortcut.in");
    ofstream fout ("shortcut.out");

    int fieldCount, pathCount; long shortcutTime;
    fin >> fieldCount >> pathCount >> shortcutTime;

    for(int k = 1; k <= fieldCount; k++){
        fin >> cows[k];
    }

    for(int k = 0; k < pathCount; k++){
        int a, b, w; fin >> a >> b >> w;
        connections[a].push_back(Connection{b, w});
        connections[b].push_back(Connection{a, w});
    }

    fill(begin(dists), end(dists), -1);
    fill(begin(parent), end(parent), -1);

    priority_queue<State,vector<State>> q;
    q.push(State{1, 0, 0});

    while (!q.empty()) {
        State cur = q.top(); q.pop();
        if (dists[cur.node] != -1) continue;
        dists[cur.node] = cur.len;
        optimal[cur.from].push_back(Connection{cur.node, -1});
        for (Connection i : connections[cur.node]) {
            if (dists[i.node] != -1) continue;
            q.push(State{i.node, cur.len + i.len, cur.node});
        }
    }

    traverse(1);
    long long answer = 0;
    for(int k = 2; k <= fieldCount; k++){
        answer = max(answer, nums[k] * (dists[k] - shortcutTime));
    }
    fout << answer << endl;
    return 0;
}