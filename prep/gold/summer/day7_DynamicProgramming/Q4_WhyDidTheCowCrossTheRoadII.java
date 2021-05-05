package day7_DynamicProgramming;

import java.io.*;

public class Q4_WhyDidTheCowCrossTheRoadII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int fieldCount = Integer.parseInt(in.readLine());
        int[][] road = new int[fieldCount][2];
        for (int i = 0; i < fieldCount; i++) {
            road[i][0] = Integer.parseInt(in.readLine());
        }
        for (int i = 0; i < fieldCount; i++) {
            road[i][1] = Integer.parseInt(in.readLine());
        }
        int[][] crossings = new int[fieldCount][fieldCount];
        for (int i = 0; i < fieldCount; i++) {
            for (int j = 0; j < fieldCount; j++) {
                int k = 0;
                if (Math.abs(road[i][0] - road[j][1]) <= 4) k++;
                if (i > 0 && j > 0) {
                    crossings[i][j] = Math.max(crossings[i - 1][j - 1] + k, Math.max(crossings[i][j], Math.max(crossings[i - 1][j], crossings[i][j - 1])));
                } else {
                    if (i == 0 && j == 0) crossings[i][j] = k;
                    else if (i == 0) crossings[i][j] = Math.max(crossings[i][j - 1], Math.max(crossings[i][j], k));
                    else crossings[i][j] = Math.max(crossings[i - 1][j], Math.max(crossings[i][j], k));
                }
            }
        }


        System.out.println(crossings[fieldCount - 1][fieldCount - 1]);
    }
}
