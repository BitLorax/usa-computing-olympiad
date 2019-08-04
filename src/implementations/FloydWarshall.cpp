//
// Created by WillJ on 1/1/2019.
//

#include <iostream>

#define INF 2000000000
#define N 1000

using namespace std;

int connections[N + 1][N + 1];

namespace floydWarshall {
    /**
     * Runs Floyd Warshall in O(N^3), saving result in the adjacency matrix
     */
    void run() {
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                if (i != j) connections[i][j] = INF;
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                for (int k = 0; k <= N; k++)
                    connections[i][j] = min(connections[i][j], connections[i][k] + connections[k][j]);
    }
}