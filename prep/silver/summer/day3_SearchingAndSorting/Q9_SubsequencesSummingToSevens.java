package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q9_SubsequencesSummingToSevens {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cowMod7 = new int[cowCount]; //prefix sums
        cowMod7[0] = 0;
        for (int i = 1; i < cowCount; i++) {
            int temp;
            temp = Integer.parseInt(in.readLine());
            cowMod7[i] = (cowMod7[i - 1] + temp) % 7;
        }
        int maxCows = 0;
        for (int i = 0; i < cowCount; i++) {
            for (int j = i + 1; j < cowCount; j++) {
                if (cowMod7[i] == cowMod7[j]    ) {
                    maxCows = Math.max(maxCows, Math.abs(i - j));
                }
            }
        }
        System.out.println(maxCows);
    }
}
