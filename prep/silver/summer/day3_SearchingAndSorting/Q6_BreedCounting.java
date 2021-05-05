package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q6_BreedCounting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int queryCount = Integer.parseInt(st.nextToken());
        int[][] cowTypeCounter = new int[cowCount][3];
        for (int i = 0; i < cowCount; i++) {
            if (i > 0) {
                System.arraycopy(cowTypeCounter[i - 1], 0, cowTypeCounter[i], 0, 3);
            }
            cowTypeCounter[i][Integer.parseInt(in.readLine()) - 1]++;
        }

        for (int i = 0; i < queryCount; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken()) - 2;
            int end = Integer.parseInt(st.nextToken()) - 1;
            for (int j = 0; j < 3; j++) {
                if (start >= 0) {
                    System.out.print(cowTypeCounter[end][j] - cowTypeCounter[start][j] + " ");
                } else {
                    System.out.print(cowTypeCounter[end][j] + " ");
                }
            }
            System.out.println();
        }
    }
}

