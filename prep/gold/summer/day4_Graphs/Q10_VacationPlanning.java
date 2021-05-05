package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q10_VacationPlanning {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int farmCount = Integer.parseInt(st.nextToken());
        int connectionCount = Integer.parseInt(st.nextToken());
        int hubCount = Integer.parseInt(st.nextToken()) - 1;
        int requestCount = Integer.parseInt(st.nextToken());
        long[][] connections = new long[farmCount][farmCount];
        for (int i = 0; i < farmCount; i++) {
            for (int j = 0; j < farmCount; j++) {
                connections[i][j] = 30000000000L;
            }
        }
        for (int i = 0; i < connectionCount; i++) {
            st = new StringTokenizer(in.readLine());
            connections[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = Integer.parseInt(st.nextToken());
        }
        for (int k = 0; k < farmCount; k++) {
            for (int i = 0; i < farmCount; i++) {
                for (int j = 0; j < farmCount; j++) {
                    connections[i][j] = Math.min(connections[i][j], connections[i][k] + connections[k][j]);
                }
            }
        }
        for (int i = 0; i < farmCount; i++) connections[i][i] = 0;
        long sum = 0;
        int successful = 0;
        for (int i = 0; i < requestCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            boolean possible = false;
            long minDist = 3000000000L;
            for (int l = 0; l <= hubCount; l++) {
                if (connections[j][l] < 3000000000L && connections[l][k] < 3000000000L) {
                    possible = true;
                    minDist = Math.min(minDist, connections[j][l] + connections[l][k]);
                }
            }
            if (possible) {
                sum += minDist;
                successful++;
            }
        }
        System.out.println(successful);
        System.out.println(sum);
    }
}
