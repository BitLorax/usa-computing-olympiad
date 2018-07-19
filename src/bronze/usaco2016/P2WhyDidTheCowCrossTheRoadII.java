package bronze.usaco2016;

import java.io.*;

public class P2WhyDidTheCowCrossTheRoadII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/circlecross.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/circlecross.out")));

        String cowsStr = in.readLine();
        char[] cows = new char[52];
        int crossings = 0;
        for (int i = 0; i < 52; i++) {
            cows[i] = cowsStr.charAt(i);
        }
        for (int i = 0; i < 26; i++) {
            char currCow = (char)(i + (int)'A');
            int first = firstAppearance(cows, currCow);
            int second = secondAppearance(cows, currCow, first);
            int[] occurences =  new int[26];
            for (int j = first + 1; j < second; j++) {
                occurences[cows[j] - 'A']++;
            }
            for (int j : occurences) {
                if (j == 1) {
                    crossings++;
                }
            }
        }

        out.println(crossings / 2);
        out.close();
    }
    private static int firstAppearance(char[] cows, char target) {
        for (int i = 0; i < 52; i++) {
            if (cows[i] == target) {
                return i;
            }
        }
        return -1;
    }
    private static int secondAppearance(char[] cows, char target, int firstAppearance) {
        for (int i = ++firstAppearance; i < 52; i++) {
            if (cows[i] == target) {
                return i;
            }
        }
        return -2;
    }
}
