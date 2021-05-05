package day7_DynamicProgramming;

import java.io.*;

public class Q1_EatingTogether {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        int[] cowsFlipped = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            int j = Integer.parseInt(in.readLine()) - 1;
            cows[i] = j;
            cowsFlipped[cowCount - 1 - i] = j;
        }
        int[][] states = new int[cowCount][3];
        for (int i = 0; i < cowCount; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != cows[i]) states[i][j]++;
                if (i == 0) continue;
                switch (j) {
                    case 0: states[i][j] += states[i - 1][j];
                    break;
                    case 1: states[i][j] = Math.min(states[i - 1][j], states[i - 1][j - 1]) + states[i][j];
                    break;
                    case 2: states[i][j] = Math.min(states[i - 1][j - 2], Math.min(states[i - 1][j], states[i - 1][j - 1])) + states[i][j];
                    break;
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i : states[cowCount - 1]) min = Math.min(min, i);
        states = new int[cowCount][3];
        for (int i = 0; i < cowCount; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != cowsFlipped[i]) states[i][j]++;
                if (i == 0) continue;
                switch (j) {
                    case 0: states[i][j] += states[i - 1][j];
                        break;
                    case 1: states[i][j] = Math.min(states[i - 1][j], states[i - 1][j - 1]) + states[i][j];
                        break;
                    case 2: states[i][j] = Math.min(states[i - 1][j - 2], Math.min(states[i - 1][j], states[i - 1][j - 1])) + states[i][j];
                        break;
                }
            }
        }
        for (int i : states[cowCount - 1]) min = Math.min(min, i);
        System.out.println(min);
    }
}
