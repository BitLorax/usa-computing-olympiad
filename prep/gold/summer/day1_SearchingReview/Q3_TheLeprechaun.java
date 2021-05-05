package day1_SearchingReview;

import java.io.*;
import java.util.StringTokenizer;

public class Q3_TheLeprechaun {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        int[][] torus = new int[len][len];
        for (int i = 0; i < len; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < len; j++) {
                torus[j][i] = Integer.parseInt(st.nextToken());
            }
        }
        int maxSum = -1 * Integer.MAX_VALUE;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int horizontalSum = 0;
                for (int k = 0; k < len; k++) {
                    horizontalSum += torus[(i + k + len) % len][j];
                    maxSum = Math.max(maxSum, horizontalSum);
                }
                int verticalSum = 0;
                for (int k = 0; k < len; k++) {
                    verticalSum += torus[i][(j + k + len) % len];
                    maxSum = Math.max(maxSum, verticalSum);
                }
                int diagonalSum1 = 0;
                for (int k = 0; k < len; k++) {
                    diagonalSum1 += torus[(i + k + len) % len][(j + k + len) % len];
                    maxSum = Math.max(maxSum, diagonalSum1);
                }
                int diagonalSum2 = 0;
                for (int k = 0; k < len; k++) {
                    diagonalSum2 += torus[(i - k + len) % len][(j + k + len) % len];
                    maxSum = Math.max(maxSum, diagonalSum2);
                }
            }
        }
        System.out.println(maxSum);
    }
}
