package day9_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q5_HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int gameCount = Integer.parseInt(st.nextToken());
        int changeCount = Integer.parseInt(st.nextToken());
        int[][][] states = new int[gameCount][changeCount + 1][4];

        int max = 0;
        for (int i = 0; i < gameCount; i++) {
            char moveChar = in.readLine().charAt(0);
            int move = -1;
            switch (moveChar) {
                case 'P': move = 0;
                break;
                case 'S': move = 1;
                break;
                case 'H': move = 2;
                break;
            }
            for (int j = 0; j <= changeCount; j++) {
                for (int k = 0; k <= 2; k++) {
                    int l = 0;
                    if (k - move == 1 || k - move == -2) l++;
                    if (i == 0) {
                        if (j == 0) {
                            states[i][j][k] = l;
                        } else {
                            states[i][j][k] = 1;
                        }
                    } else {
                        if (j > 0) states[i][j][k] = Math.max(states[i - 1][j][k] + l, states[i - 1][j - 1][3] + l);
                        else states[i][j][k] = states[i - 1][j][k] + l;
                    }
                    states[i][j][3] = Math.max(states[i][j][3], states[i][j][k]);
                    max = Math.max(max, states[i][j][k]);
                }
            }
        }

        System.out.println(max);
    }
}
