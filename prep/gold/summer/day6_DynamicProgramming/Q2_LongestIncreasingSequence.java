package day6_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q2_LongestIncreasingSequence {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int numCount = Integer.parseInt(in.readLine());
        int[] nums = new int[numCount];
        for (int i = 0; i < numCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int[] len = new int[numCount];
        for (int i = 0; i < numCount; i++) {
            len[i] = 1;
        }
        for (int i = numCount - 1; i >= 0; i--) {
            for (int j = i + 1; j < numCount; j++) {
                if (nums[j] <= nums[i]) continue;
                len[i] = Math.max(len[i], len[j] + 1);
            }
        }
        int max = 0;
        for (int i : len) {
            max = Math.max(max, i);
        }
        System.out.println(max);
    }
}
