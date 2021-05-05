package day10_DynamicProgramming;

import java.io.*;

public class Q6_BaleShare {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int baleCount = Integer.parseInt(in.readLine());
        int[] baleInfo = new int[baleCount];
        int sum = 0;
        for (int i = 0; i < baleCount; i++) {
            int j = Integer.parseInt(in.readLine());
            baleInfo[i] = j;
            sum += j;
        }
        boolean[][] states = new boolean[800][800];
        states[0][0] = true;
        for (int k = 0; k < baleCount; k++) {
            for (int i = 700; i >= 0; i--) {
                for (int j = 700; j >= 0; j--) {
                    if (i - baleInfo[k] >= 0 && states[i - baleInfo[k]][j]) states[i][j] = true;
                    if (j - baleInfo[k] >= 0 && states[i][j - baleInfo[k]]) states[i][j] = true;
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i <= 700; i++) {
            for (int j = 0; j <= 700; j++) {
                if (states[i][j]) min = Math.min(min, Math.max(sum - i - j, Math.max(i, j)));
            }
        }
        System.out.println(min);
    }
}
