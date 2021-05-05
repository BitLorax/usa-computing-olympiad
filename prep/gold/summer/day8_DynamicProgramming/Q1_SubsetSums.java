package day8_DynamicProgramming;

import java.io.*;

public class Q1_SubsetSums {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int integerCount = Integer.parseInt(in.readLine());
        int sum = integerCount * (integerCount + 1) / 2;
        long[] possibilities = new long[sum + 1];

        if (sum % 2 == 0) {
            sum /= 2;
            possibilities[0] = 1;
            for (int i = 1; i <= integerCount; i++) {
                for (int j = sum; j >= i; j--) {
                    possibilities[j] += possibilities[j - i];
                }
            }
            System.out.println(possibilities[sum] / 2);
        } else {
            System.out.println(0);
        }
    }
}
