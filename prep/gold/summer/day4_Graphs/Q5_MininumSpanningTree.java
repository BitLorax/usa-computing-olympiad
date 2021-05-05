package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q5_MininumSpanningTree {
    private static int[][] connections;
    private static int[] distances;
    private static boolean[] visited;
    private static int accessed = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int vertexCount = Integer.parseInt(st.nextToken());
        int edgeCount = Integer.parseInt(st.nextToken());
        connections = new int[vertexCount][vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                connections[i][j] = Integer.MAX_VALUE;
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
        distances = new int[vertexCount];
        for (int i = 1; i < vertexCount; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        visited = new boolean[vertexCount];
        prims(0);
        int j = 0;
        for (int i : distances) {
            j += i;
        }
        System.out.println(j);
    }
    private static void prims(int pos) {
        visited[pos] = true;
        accessed++;
        int closestVertex = -1;
        int closestDist = Integer.MAX_VALUE;
        for (int i = 0; i < connections.length; i++) {
            if (visited[i]) continue;
            distances[i] = Math.min(distances[i], connections[pos][i]);
            if (distances[i] != 0 && distances[i] < closestDist) {
                closestDist = distances[i];
                closestVertex = i;
            }
        }
        if (accessed < connections.length) prims(closestVertex);
    }
}
