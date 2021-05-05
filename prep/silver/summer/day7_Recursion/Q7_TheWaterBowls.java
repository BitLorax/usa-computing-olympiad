package day7_Recursion;

import java.util.Scanner;

public class Q7_TheWaterBowls {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] bowls = new int[20];
        for (int i = 0; i < 20; i++) {
            bowls[i] = in.nextInt();
        }
        int minFlipped = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << 20); i++) {
            int flipped = 0;
            int[] flippedBowls = bowls.clone();
            for (int j = 0 ; j < 20; j++) {
                if ((i & (1 << j)) != 0) {
                    if (j > 0) {
                        flippedBowls[j - 1] = Math.abs(flippedBowls[j - 1] - 1);
                    }
                    flippedBowls[j] = Math.abs(flippedBowls[j] - 1);
                    if (j < 19) {
                        flippedBowls[j + 1] = Math.abs(flippedBowls[j + 1] - 1);
                    }
                    flipped++;
                }
            }
            boolean complete = true;
            for (int j = 0; j < 20; j++) {
                if (flippedBowls[j] == 1) {
                    complete = false;
                }
            }
            if (complete) {
                minFlipped = Math.min(minFlipped, flipped);
            }
        }
        System.out.println(minFlipped);
    }
}
