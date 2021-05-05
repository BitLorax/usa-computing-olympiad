package day_15_Final;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q3_MakingChange {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int value = Integer.parseInt(st.nextToken());
        int coinCount = Integer.parseInt(st.nextToken());
        int[] coins = new int[coinCount];
        for (int i = 0; i < coinCount; i++) {
            coins[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(coins);
        int states[] = new int[value + 1];
        for (int i = 1; i <= value; i++) states[i] = 1000000000;
        for (int i = 0; i <= value; i++) {
            for (int j : coins) {
                if (i - j < 0) continue;
                if (states[i - j] != 1000000000) states[i] = Math.min(states[i], states[i - j] + 1);
            }
        }
        /*
        int coinsUsed = 0;
        for (int i = coinCount - 1; i >= 0; i--) {
            int k = value / coins[i];
            coinsUsed += k;
            value -= k * coins[i];
        }
        */
        System.out.println(states[value]);
    }
}
