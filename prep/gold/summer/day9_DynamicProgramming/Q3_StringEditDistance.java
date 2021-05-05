package day9_DynamicProgramming;

import java.io.*;

public class Q3_StringEditDistance {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String one = in.readLine();
        String two = in.readLine();
        int[][] changes = new int[one.length() + 1][two.length() + 1];
        for (int i = 0; i <= one.length(); i++) changes[i][0] = i;
        for (int i = 0; i <= two.length(); i++) changes[0][i] = i;
        for (int i = 1; i <= one.length(); i++) {
            for (int j = 1; j <= two.length(); j++) {
                int k = 0;
                if (one.charAt(i - 1) != two.charAt(j - 1)) k++;
                changes[i][j] = Math.min(changes[i - 1][j - 1] + k, Math.min(changes[i - 1][j] + 1, changes[i][j - 1] + 1));
            }
        }
        System.out.println(changes[one.length()][two.length()]);
    }
}
