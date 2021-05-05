package day1_SearchingReview;

import java.io.*;
import java.util.StringTokenizer;

public class Q1_BackwardDigitSums {
    private static int numberCount;
    private static int finalSum;
    private static boolean found = false;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        numberCount = Integer.parseInt(st.nextToken());
        finalSum = Integer.parseInt(st.nextToken());

        getCombination(new int[numberCount], 0);
    }
    private static void getCombination(int[] result, int index) {
        if (!found) {
            if (index == numberCount) {
                if (getPairs(result) == finalSum) {
                    System.out.println(toString(result));
                    found = true;
                }
            } else {
                for (int i = 1; i <= numberCount; i++) {
                    int[] j = result.clone();
                    if (!contains(j, i)) {
                        j[index] = i;
                        getCombination(j, index + 1);
                    }
                }
            }
        }
    }
    private static boolean contains(int[] test, int target) {
        for (int i : test) {
            if (i == target) return true;
        }
        return false;
    }
    private static String toString(int[] in) {
        String k = "";
        for (int i : in) {
            k += i + " ";
        }
        return k;
    }
    private static int getPairs(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int[] nextRow = new int[nums.length - 1];
        for (int i = 0; i < nums.length - 1; i++) {
            nextRow[i] = nums[i] + nums[i + 1];
        }
        return getPairs(nextRow);
    }
}
