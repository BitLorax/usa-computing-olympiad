package day15_Final;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q3_EscapingTheFarm {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = Integer.parseInt(in.readLine());
        }

        int maxCows = 0;
        for (int i = 0; i < (1 << cowCount); i++) {
            int cowsUsed = 0;
            int[] digits = new int[9];
            for (int j = 0; j < cowCount; j++) {
                if ((i & (1 << j)) != 0) {
                    cowsUsed++;
                    int cowWeight = cows[j];
                    int index = 0;
                    while (cowWeight != 0) {
                        int temp = cowWeight / 10;
                        temp *= 10; //temp gets rid of ones place
                        digits[index] += cowWeight - temp;
                        cowWeight /= 10;
                        index++;
                    }
                }
            }
            boolean success = true;
            for (int j = 0; j < 9; j++) {
                if (digits[j] >= 10) {
                    success = false;
                }
            }
            if (success) {
                maxCows = Math.max(maxCows, cowsUsed);
            }
        }
        System.out.println(maxCows);
    }
}
