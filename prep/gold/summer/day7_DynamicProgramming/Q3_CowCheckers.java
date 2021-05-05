package day7_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q3_CowCheckers {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());
        int maxLen = Math.max(height, width);
        int[] loseLocations = new int[maxLen];
        for (int i = 0; i < loseLocations.length; i++) {
            loseLocations[i] = -1;
        }
        int pos = 0;
        for (int i = 0; i < maxLen; i++) {
            if (loseLocations[i] == -1) {
                loseLocations[i] = pos;
                loseLocations[pos] = i;
                pos++;
            }
            pos++;
            if (pos >= maxLen) break;
        }
        int gameCount = Integer.parseInt(in.readLine());
        for (int i = 0; i < gameCount; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (loseLocations[x] == y) System.out.println("Farmer John");
            else System.out.println("Bessie");
        }
    }
}
