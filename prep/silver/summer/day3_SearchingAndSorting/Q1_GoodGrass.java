package day3_SearchingAndSorting;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Q1_GoodGrass {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());

        int[][] map = new int[width][height];
        for (int i = 0; i < height; i++) {
            st = new StringTokenizer(in.nextLine());
            for (int j = 0; j < width; j++) {
                map[j][i] = Integer.parseInt(st.nextToken());
            }
        }
        int total = 0;
        int maxTotal = 0;
        int row = 0;
        int column = 0;
        for (int i = 0; i < height - 3; i++) {
            for (int j = 0; j < width - 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        total += map[j + k][i + l];
                    }
                }
                if (total > maxTotal) {
                    maxTotal = total;
                    column = j;
                    row = i;
                }
                total = 0;
            }
        }
        System.out.println(maxTotal);
        System.out.println((row + 1) + " " + (column + 1));
    }
}
