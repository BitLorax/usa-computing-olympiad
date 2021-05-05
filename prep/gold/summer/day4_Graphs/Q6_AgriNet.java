package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q6_AgriNet {
    private static int[][] connections;
    private static int[] distances;
    private static boolean[] visited;
    private static int accessed = 1;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int farmCount = Integer.parseInt(in.readLine());
        connections = new int[farmCount][farmCount];
        int k = 0;
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < farmCount; i++) {
            for (int j = k; j < farmCount; j++) {
                connections[j][i] = Integer.parseInt(st.nextToken());
                if (!st.hasMoreTokens() && !(i == farmCount - 1 && j == farmCount - 1)) st = new StringTokenizer(in.readLine());
            }
        }
        distances = new int[farmCount];
        for (int i = 1; i < farmCount; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        visited = new boolean[farmCount];
        prims(0);
        int sum = 0;
        for (int i : distances) {
            sum += i;
        }
        System.out.println(sum);
    }
    private static void prims(int pos) {
        visited[pos] = true;
        accessed++;
        int minDist = Integer.MAX_VALUE;
        int closestVertex = -1;
        for (int i = 0; i < connections.length; i++) {
            if (visited[i]) continue;
            distances[i] = Math.min(distances[i], connections[pos][i]);
            if (distances[i] != 0 && distances[i] < minDist) {
                minDist = distances[i];
                closestVertex = i;
            }
        }
        if (accessed < connections.length) prims(closestVertex);
    }
}
