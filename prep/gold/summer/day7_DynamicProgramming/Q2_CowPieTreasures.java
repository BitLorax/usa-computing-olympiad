package day7_DynamicProgramming;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q2_CowPieTreasures {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int[][] map = new int[width][height];
        for (int i = 0; i < height; i++) {
            st = new StringTokenizer(in.readLine());
            for (int j = 0; j < width; j++) {
                map[j][i] = Integer.parseInt(st.nextToken());
            }
        }
        int[][] vals = new int[width][ height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                vals[i][j] = Integer.MIN_VALUE;
            }
        }
        vals[0][0] = map[0][0];
        for (int i = 1; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (j == 0) vals[i][j] = Math.max(vals[i - 1][j], vals[i - 1][j + 1]) + map[i][j];
                else if (j == height - 1) vals[i][j] = Math.max(vals[i - 1][j], vals[i - 1][j - 1]) + map[i][j];
                else vals[i][j] = Math.max(vals[i - 1][j], Math.max(vals[i - 1][j - 1], vals[i - 1][j + 1])) + map[i][j];
            }
        }
        System.out.println(vals[width - 1][height - 1]);
    }
}
