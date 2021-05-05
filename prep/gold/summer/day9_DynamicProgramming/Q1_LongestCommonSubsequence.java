package day9_DynamicProgramming;

import java.io.*;

public class Q1_LongestCommonSubsequence {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String one = in.readLine();
        String two = in.readLine();
        int[][] substrings = new int[one.length() + 1][two.length() + 1];

        for (int i = 1; i <= one.length(); i++) {
            for (int j = 1; j <= two.length(); j++) {
                if (one.charAt(i - 1) == two.charAt(j - 1)) substrings[i][j] = substrings[i - 1][j - 1] + 1;
                else substrings[i][j] = Math.max(substrings[i - 1][j], substrings[i][j - 1]);
            }
        }
        System.out.println(substrings[one.length()][two.length()]);
    }
}
