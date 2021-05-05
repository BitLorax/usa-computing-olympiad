package day10_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1_TheLeisurelyStroll {
    private static int maxLen = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int nodeCount = Integer.parseInt(in.readLine()) - 1;
        int[][] nodes = new int[nodeCount][2];
        for (int i = 0; i < nodeCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int nodeNum = Integer.parseInt(st.nextToken()) - 1;
            int dest1 = Integer.parseInt(st.nextToken()) - 1;
            int dest2 = Integer.parseInt(st.nextToken()) - 1;
            nodes[nodeNum][0] = dest1;
            nodes[nodeNum][1] = dest2;
        }
        followPath(nodes, 0, -1);
        System.out.println(maxLen);
    }
    private static void followPath(int[][] nodes, int currNode, int currLen) {
        currLen++;
        maxLen = Math.max(maxLen, currLen);
        if (currNode == -1) {
            return;
        }
        for (int i = 0; i < 2; i++) {
            followPath(nodes, nodes[currNode][i], currLen);
        }
    }
}
