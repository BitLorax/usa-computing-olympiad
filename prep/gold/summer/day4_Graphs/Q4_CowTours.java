package day4_Graphs;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q4_CowTours {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int pastureCount = Integer.parseInt(in.readLine());
        Coord[] pastureInfo = new Coord[pastureCount];
        for (int i = 0; i < pastureCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            pastureInfo[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        double[][] connections = new double[pastureCount][pastureCount];
        for (int i = 0; i < pastureCount; i++) {
            String row = in.readLine();
            for (int j = 0; j < pastureCount; j++) {
                if (row.substring(j, j + 1).equals("1")) {
                    connections[j][i] = getDist(pastureInfo[i], pastureInfo[j]);
                } else {
                    connections[j][i] = Double.MAX_VALUE;
                }
            }
        }
        for (int i = 0; i < pastureCount; i++) connections[i][i] = 0;
        for (int k = 0; k < pastureCount; k++) {
            for (int i = 0; i < pastureCount; i++) {
                for (int j = 0; j < pastureCount; j++) {
                    connections[i][j] = Math.min(connections[i][j], connections[i][k] + connections[j][k]);
                }
            }
        }

        double[] maxDists = new double[pastureCount];
        for (int i = 0; i < pastureCount; i++) {
            for (int j = 0; j < pastureCount; j++) {
                if (connections[i][j] == Double.MAX_VALUE || connections[i][j] == 0) continue;
                maxDists[i] = Math.max(maxDists[i], connections[i][j]);
            }
        }
        double[] maxDiameter = new double[pastureCount];
        Arrays.fill(maxDiameter, 0.0);
        for (int i = 0; i < pastureCount; i++) {
            double max = 0;
            for (int j = 0; j < pastureCount; j++) {
                if (connections[i][j] != Double.MAX_VALUE) max = Math.max(max, connections[i][j]);
            }
            for (int j = 0; j < pastureCount; j++) {
                if (connections[i][j] != Double.MAX_VALUE) maxDiameter[j] = Math.max(max, maxDiameter[j]);
            }
        }
        Double minDiameter = Double.MAX_VALUE;
        for (int i = 0; i < pastureCount; i++) {
            for (int j = 0; j < pastureCount; j++) {
                if (connections[i][j] == Double.MAX_VALUE) {
                    double k = getDist(pastureInfo[i], pastureInfo[j]);
                    minDiameter = Math.min(minDiameter, Math.max(k + maxDists[i] + maxDists[j], Math.max(maxDiameter[i], maxDiameter[j])));
                }
            }
        }
        System.out.println(String.format("%.6f", minDiameter));
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
