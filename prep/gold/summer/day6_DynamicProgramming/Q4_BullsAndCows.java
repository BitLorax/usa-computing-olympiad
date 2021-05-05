package day6_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q4_BullsAndCows {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int dist = Integer.parseInt(st.nextToken()) + 1;
        int[] possibilities = new int[cowCount + 1];
        for (int i = 0; i < cowCount + 1; i++) {
            if (i <= dist) possibilities[i] = i;
            else possibilities[i] = -1;
        }
        long sum = 0;
        for (int j = 1; j <= cowCount; j++) {
            long l = 0;
            l += j;
            if (j > dist) sum = sum + possibilities[j - dist];
            l += sum;
            possibilities[j] = (int)(l % 5000011);
        }
        System.out.println((possibilities[cowCount] + 1) % 5000011);
    }
}
