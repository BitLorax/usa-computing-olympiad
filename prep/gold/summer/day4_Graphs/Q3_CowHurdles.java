package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q3_CowHurdles {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int stationCount = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        int taskCount = Integer.parseInt(st.nextToken());
        int[][] hurdles = new int[stationCount][stationCount];
        for (int i = 0; i < stationCount; i++) {
            for (int j = 0; j < stationCount; j++) {
                hurdles[i][j] = 1000000000;
            }
        }
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            hurdles[j][k] = l;
        }
        for (int k = 0; k < stationCount; k++) {
            for (int i = 0; i < stationCount; i++) {
                for (int j = 0; j < stationCount; j++) {
                    hurdles[i][j] = Math.min(hurdles[i][j], Math.max(hurdles[i][k], hurdles[k][j]));
                }
            }
        }
        for (int i = 0; i < taskCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            if (hurdles[j][k] != 1000000000) System.out.println(hurdles[j][k]);
            else System.out.println("-1");
        }
    }
}
