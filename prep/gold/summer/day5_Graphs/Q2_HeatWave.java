package day5_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q2_HeatWave {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int townCount = Integer.parseInt(st.nextToken());
        int connectionCount = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken()) - 1;
        int end = Integer.parseInt(st.nextToken()) - 1;
        int[][] connections = new int[townCount][townCount];
        for (int i = 0; i < townCount; i++) {
            for (int j = 0; j < townCount; j++) {
                connections[j][i] = 1000000000;
            }
        }
        for (int i = 0; i < connectionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            connections[j][k] = l;
            connections[k][j] = l;
        }
        int[] minDists = new int[townCount];
        for (int i = 0; i < townCount; i++) {
            minDists[i] = 1000000000;
        }
        minDists[start] = 0;
        boolean[] visited = new boolean[townCount];
        for (int i = 0; i < townCount; i++) {
            int minDist = 1000000001;
            int closestTown = -1;
            for (int j = 0; j < townCount; j++) {
                if (!visited[j] && minDists[j] < minDist) {
                    minDist = minDists[j];
                    closestTown = j;
                }
            }
            visited[closestTown] = true;
            for (int j = 0; j < townCount; j++) {
                minDists[j] = Math.min(minDists[j], minDists[closestTown] + connections[closestTown][j]);
            }
        }
        System.out.println(minDists[end]);
    }
}
