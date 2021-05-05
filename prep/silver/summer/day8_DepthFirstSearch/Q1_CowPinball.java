package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1_CowPinball {
    private static int maxScore = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        int[][] pinball = new int[len][len];
        for (int i = 0; i < len; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < i + 1; j++) {
                pinball[j][i] = Integer.parseInt(st.nextToken());
            }
        }
        getPinball(pinball, 0,0, 0);
        System.out.println(maxScore);
    }
    private static void getPinball(int[][] pinball, int x, int y, int score) {
        if (y == pinball.length) {
            maxScore = Math.max(score, maxScore);
        } else {
            score += pinball[x][y];
            int SCORE = score;
            int X = x;
            int Y = y;

            getPinball(pinball, x, y + 1, score);

            score = SCORE;
            x = X;
            y = Y;
            getPinball(pinball, x + 1, y + 1, score);
        }
    }
}
