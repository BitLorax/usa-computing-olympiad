package day14_CompleteSearch_HardImplementations;

import java.util.Scanner;

public class Q2_TheEatingPuzzleII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int limit = in.nextInt();
        int bucketCount = in.nextInt();
        int[] buckets = new int[bucketCount];
        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = in.nextInt();
        }

        int maxSum = 0;
        for (int i = 0; i < (1 << bucketCount); i++) {
            int sum = 0;
            for (int j = 0; j < bucketCount; j++) {
                if ((i & (1 << j))!= 0) {
                    sum += buckets[j];
                }
            }
            if (sum <= limit) {
                maxSum = Math.max(maxSum, sum);
            }
        }
        System.out.println(maxSum);
    }
}
