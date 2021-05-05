package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q9_JobHunt {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int maxMoneyPerCity = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        int cityCount = Integer.parseInt(st.nextToken());
        int paidPathCount = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken()) - 1;
        int[][] connections = new int[cityCount][cityCount];
        for (int i = 0; i < cityCount; i++) for (int j = 0; j < cityCount; j++) connections[i][j] = -1000000000;
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            connections[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = maxMoneyPerCity;
        }
        for (int i = 0; i < paidPathCount; i++) {
            st = new StringTokenizer(in.readLine());
            connections[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken())- 1] = maxMoneyPerCity - Integer.parseInt(st.nextToken());
        }
        for (int k = 0; k < cityCount; k++) {
            for (int i = 0; i < cityCount; i++) {
                for (int j = 0; j < cityCount; j++) {
                    connections[i][j] = Math.max(connections[i][j], connections[i][k] + connections[k][j]);
                }
            }
        }
        boolean infiniteLoop = false;
        for (int i = 0; i < cityCount; i++) {
            if (connections[i][i] > 0) {
                System.out.println(-1);
                infiniteLoop = true;
            }
        }
        if (!infiniteLoop) {
            int max = 0;
            for (int i : connections[start]) max = Math.max(max, i);
            System.out.println(max + maxMoneyPerCity);
        }
    }
}
