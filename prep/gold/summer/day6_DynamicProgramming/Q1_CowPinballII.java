package day6_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q1_CowPinballII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        int[][] values = new int[len][len];
        for (int i = 0; i < len; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < i + 1; j++) {
                values[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = len - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                values[i][j] = values[i][j] + Math.max(values[i + 1][j], values[i + 1][j + 1]);
            }
        }
        System.out.println(values[0][0]);
    }
}
