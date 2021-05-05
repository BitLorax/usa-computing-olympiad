package day8_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q5_HayForSale {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int capacity = Integer.parseInt(st.nextToken());
        int baleCount = Integer.parseInt(st.nextToken());
        int[] baleInfo = new int[baleCount];
        for (int i = 0; i < baleCount; i++) {
            int j = Integer.parseInt(in.readLine());
            baleInfo[i] = j;
        }
        int[] possibilities = new int[capacity + 1];
        for (int i = 0; i < baleCount; i++) {
            for (int j = capacity; j >= baleInfo[i]; j--) {
                possibilities[j] = Math.max(possibilities[j], possibilities[j - baleInfo[i]] + baleInfo[i]);
            }
        }
        int max = 0;
        for (int i : possibilities) max = Math.max(max, i);
        System.out.println(max);
    }
}
