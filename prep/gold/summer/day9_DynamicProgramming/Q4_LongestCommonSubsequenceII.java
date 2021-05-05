package day9_DynamicProgramming;

import java.io.*;

public class Q4_LongestCommonSubsequenceII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String one = in.readLine();
        String two = in.readLine();
        int[][] substrings = new int[one.length() + 1][2];
        for (int j = 1; j <= two.length(); j++) {
            for (int i = 1; i <= one.length(); i++) {
                if (one.charAt(i - 1) == two.charAt(j - 1)) substrings[i][j % 2] = substrings[i - 1][(j + 1) % 2] + 1;
                else substrings[i][j % 2] = Math.max(substrings[i - 1][j % 2], substrings[i][(j + 1) % 2]);
            }
        }
        System.out.println(substrings[one.length()][two.length() % 2]);
    }
}
