package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Q1_HayBales {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int pileCount = Integer.parseInt(in.readLine());
        int[] piles = new int[pileCount];
        int total = 0;
        for (int i = 0; i < pileCount; i++) {
            int height = Integer.parseInt(in.readLine());
            piles[i] = height;
            total += height;
        }
        int mean = total / pileCount;
        int change = 0;
        Arrays.sort(piles);
        for (int height : piles) {
            if (height - mean < 0) {
                change -= (height - mean);
            } else {
                break;
            }
        }

        System.out.println(change);
    }
}
