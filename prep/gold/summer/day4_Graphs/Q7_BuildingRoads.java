package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q7_BuildingRoads {
    private static boolean[][] connections;
    private static double[] distances;
    private static boolean[] visited;
    private static int accessed = 1;
    private static Coord[] farmInfo;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int farmCount = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        farmInfo = new Coord[farmCount];
        for (int i = 0; i < farmCount; i++) {
            st = new StringTokenizer(in.readLine());
            farmInfo[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        connections = new boolean[farmCount][farmCount];
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            connections[j][k] = true;
            connections[k][j] = true;
        }
        distances = new double[farmCount];
        for (int i = 1; i < farmCount; i++) distances[i] = Double.MAX_VALUE;
        visited = new boolean[farmCount];
        prims(0);
        double sum = 0;
        for (double i : distances) {
            sum += i;
        }
        /*
        for (int i = 0; i < farmCount; i++) {
            for (int j = i + 1; j < farmCount; j++) {
                if (connections[i][j]) sum -= getDist(farmInfo[i], farmInfo[j]);
            }
        }
        */
        System.out.println(String.format("%.2f", sum));
    }
    private static void prims(int pos) {
        visited[pos] = true;
        accessed++;
        double closestDist = Double.MAX_VALUE;
        int closestFarm = -1;
        for (int i = 0; i < distances.length; i++) {
            if (visited[i]) continue;
            if (connections[pos][i]) {
                distances[i] = 0;
            }
            distances[i] = Math.min(distances[i], getDist(farmInfo[pos], farmInfo[i]));
            if (distances[i] < closestDist) {
                closestDist = distances[i];
                closestFarm = i;
            }
        }
        if (accessed < distances.length) prims(closestFarm);
    }
    private static double getDist(Coord a, Coord b) {
        return Math.sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
    }
    static class Coord {
        int x;
        int y;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
