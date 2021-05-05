package day8_DynamicProgramming;

import java.io.*;

public class Q4_DividingTheGold {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int coinCount = Integer.parseInt(in.readLine());
        int[] coinInfo = new int[coinCount];
        int sum = 0;
        for (int i = 0; i < coinCount; i++) {
            int j = Integer.parseInt(in.readLine());
            coinInfo[i] = j;
            sum += j;
        }
        long[] possibilities = new long[sum + 1];
        possibilities[0] = 1;
        for (int i = 0; i < coinCount; i++) {
            for (int j = sum; j >= coinInfo[i]; j--) {
                possibilities[j] += possibilities[j - coinInfo[i]];
                if (possibilities[j] > 1000000) possibilities[j] %= 10000000;
            }
        }
        int k = sum / 2;
        if (sum % 2 == 1) k++;
        while (possibilities[k] == 0 && possibilities[sum - k] == 0) k++;
        System.out.println(k - (sum - k));
        System.out.println(possibilities[Math.max(k, sum - k)] % 1000000);
    }
}
