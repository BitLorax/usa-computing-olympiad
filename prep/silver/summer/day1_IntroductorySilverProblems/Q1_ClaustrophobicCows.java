package day1_IntroductorySilverProblems;

import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q1_ClaustrophobicCows {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cowNum = Integer.parseInt(in.nextLine());
        int[][] coords = new int[2][cowNum];
        for (int i = 0; i < cowNum; i++) {
            StringTokenizer st = new StringTokenizer(in.nextLine());
            coords[0][i] = Integer.parseInt(st.nextToken());
            coords[1][i] = Integer.parseInt(st.nextToken());
        }
        long minDist = dist(coords[0][0], coords[1][0], coords[0][1], coords[1][1]);
        int[] minCowID = new int[2];
        for (int i = 0; i < cowNum; i++) {
            for (int j = i + 1; j < cowNum; j++) {
                long dist = dist(coords[0][i], coords[1][i], coords[0][j], coords[1][j]);
                if (dist < minDist) {
                    minDist = dist;
                    minCowID[0] = i;
                    minCowID[1] = j;
                }
            }
        }
        Arrays.sort(minCowID);
        System.out.println((minCowID[0] + 1) + " " + (minCowID[1] + 1));
    }
    private static long dist(int x1, int y1, int x2, int y2) {
        return (long)(Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2));
    }
}
