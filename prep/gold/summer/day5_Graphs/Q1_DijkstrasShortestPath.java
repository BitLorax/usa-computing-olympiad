package day5_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q1_DijkstrasShortestPath {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int vertexCount = Integer.parseInt(st.nextToken());
        int edgeCount = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken()) - 1;
        int[][] connections = new int[vertexCount][vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                connections[i][j] = 1000000000;
            }
        }
        for (int i = 0; i < edgeCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            connections[j][k] = l;
            connections[k][j] = l;
        }
        int[] minDists = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            minDists[i] = 1000000000;
        }
        minDists[start] = 0;
        boolean[] visited = new boolean[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            int minDist = 1000000001;
            int closestVertex = -1;
            for (int j = 0; j < minDists.length; j++) {
                if (minDists[j] < minDist && !visited[j]) {
                    minDist = minDists[j];
                    closestVertex = j;
                }
            }
            visited[closestVertex] = true;
            for (int j = 0; j < minDists.length; j++) {
                minDists[j] = Math.min(minDists[j], minDists[closestVertex] + connections[closestVertex][j]);
            }
        }
        for (int i : minDists) {
            if (i == 1000000000) System.out.println("-1");
            else System.out.println(i);
        }
    }
}
