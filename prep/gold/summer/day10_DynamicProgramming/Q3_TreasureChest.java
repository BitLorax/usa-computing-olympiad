package day10_DynamicProgramming;

import java.io.*;

public class Q3_TreasureChest {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int coinCount = Integer.parseInt(in.readLine());
        int[] sums = new int[coinCount];
        int[] states = new int[coinCount];
        int sum = 0;
        for (int i = 0; i < coinCount; i++) {
            int j = Integer.parseInt(in.readLine());
            states[i] = j;
            sum += j;
            sums[i] = sum;
        }
        for (int len = 1; len < coinCount; len++) {
            for (int i = 0; i + len < coinCount; i++) {
                int j = sums[i + len] - ((i - 1 >= 0) ? sums[i - 1] : 0);
                states[i] = j - Math.min(states[i], states[i + 1]);
            }
        }

        System.out.println(states[0]);
    }
}
