package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q4_Sets_AllNDigitNumbers {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(in.readLine());
        int[] nums = new int[m];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < m; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int n = Integer.parseInt(in.readLine());
        getAllNums(nums, n, n, "");
    }
    private static void getAllNums(int[] nums, int n, int N, String curr) {
        String startCurr = curr;
        for (int num : nums) {
            curr = startCurr;
            if (n == N) {
                curr += num;
                getAllNums(nums, n - 1, N, curr);
            } else if (n > 1) {
                curr += num;
                getAllNums(nums, n - 1, N, curr);
            } else {
                curr += num;
                System.out.println(curr);
            }
        }
    }
}
