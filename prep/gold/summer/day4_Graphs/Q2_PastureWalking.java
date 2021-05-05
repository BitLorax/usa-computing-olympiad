package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q2_PastureWalking {
    private static int[][] connections;
    private static int ans;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int visitCount = Integer.parseInt(st.nextToken());
        connections = new int[cowCount][cowCount];
        for (int i = 0; i < cowCount; i++) {
            for (int j = 0; j < cowCount; j++) {
                connections[i][j] = 1000000000;
            }
        }
        for (int i = 0; i < cowCount - 1; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            connections[j][k] = l;
            connections[k][j] = l;
        }
        for (int k = 0; k < cowCount; k++) {
            for (int i = 0; i < cowCount; i++) {
                for (int j = 0; j < cowCount; j++) {
                    connections[i][j] = Math.min(connections[i][j], connections[i][k] + connections[k][j]);
                }
            }
        }
        for (int i = 0; i < visitCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            //followPath(j, k, new boolean[cowCount], 0);
            System.out.println(connections[j][k]);
        }
    }
    private static void followPath(int pos, int target, boolean[] visited, int len) {
        if (pos == target) ans = len;
        visited[pos] = true;
        for (int i = 0; i < connections.length; i++) {
            if (connections[pos][i] > 0 && !visited[i]) followPath(i, target, visited, len + connections[pos][i]);
        }
    }

}
