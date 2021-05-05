package day5_Graphs;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q3_PowerFailure {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int poleCount = Integer.parseInt(st.nextToken());
        int wireCount = Integer.parseInt(st.nextToken());
        double maxWireLen = Double.parseDouble(in.readLine());
        double[][] distances = new double[poleCount][poleCount];
        Coord[] poleInfo = new Coord[poleCount];
        for (int i = 0; i < poleCount; i++) {
            st = new StringTokenizer(in.readLine());
            poleInfo[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        for (int i = 0; i < poleCount; i++) {
            for (int j = 0; j < poleCount; j++) {
                double k = getDist(poleInfo[i], poleInfo[j]);
                if (k > maxWireLen) distances[i][j] = 1000000000;
                else distances[i][j] = k;
            }
        }
        for (int i = 0; i < wireCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            distances[j][k] = 0;
            distances[k][j] = 0;
        }

        double[] minDistance = new double[poleCount];
        for (int i = 1; i < poleCount; i++) {
            minDistance[i] = 1000000000;
        }
        boolean[] visited = new boolean[poleCount];
        for (int i = 0; i < poleCount; i++) {
            double minDist = 1000000001;
            int closestPole = -1;
            for (int j = 0; j < minDistance.length; j++) {
                if (minDistance[j] < minDist && !visited[j]) {
                    minDist = minDistance[j];
                    closestPole = j;
                }
            }
            visited[closestPole] = true;
            for (int j = 0; j < poleCount; j++) {
                if (closestPole == j) continue;
                minDistance[j] = Math.min(minDistance[j], minDistance[closestPole] + distances[closestPole][j]);
            }
        }
        int i = (int)(minDistance[poleCount - 1] * 1000);
        if (i == Integer.MAX_VALUE) System.out.println("-1");
        else System.out.println(i);
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
