package day2_SearchingAndSorting;

import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q1_ThePerfectCow {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int sideLen = Integer.parseInt(in.nextLine());
        int[][] cows = new int[sideLen][sideLen];
        for (int i = 0; i < sideLen; i++) {
            StringTokenizer st = new StringTokenizer(in.nextLine());
            for (int j = 0; j < sideLen; j++) {
                cows[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < sideLen; i++) {
            Arrays.sort(cows[i]);
        }

        int[] medianRow = new int[sideLen];
        for (int i = 0; i < sideLen; i++) {
            medianRow[i] = cows[i][(sideLen - 1) / 2];
        }

        Arrays.sort(medianRow);
        System.out.println(medianRow[(sideLen - 1) / 2]);
    }
}
