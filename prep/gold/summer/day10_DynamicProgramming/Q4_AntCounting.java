package day10_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q4_AntCounting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int familyCount = Integer.parseInt(st.nextToken());
        int antCount = Integer.parseInt(st.nextToken());
        int lowerLimit = Integer.parseInt(st.nextToken());
        int upperLimit = Integer.parseInt(st.nextToken());
        int[] ants = new int[familyCount];
        for (int i = 0; i < antCount; i++) {
            ants[Integer.parseInt(in.readLine()) - 1]++;
        }
        long[][] states = new long[familyCount + 1][antCount + 1];
        for (int i = 0; i <= familyCount; i++) states[i][0] = 1;
        for (int i = 1; i <= familyCount; i++) {
            for (int j = 1; j <= antCount; j++) {
                int k = j;
                long sum = 0;
                while (k >= 0 && (j - k) <= ants[i - 1]) {
                    sum += states[i - 1][k];
                    sum %= 1000000;
                    k--;
                }
                states[i][j] = sum;
            }
        }
        int sum = 0;
        for (int i = lowerLimit; i <= upperLimit; i++) sum += states[familyCount][i];
        System.out.println(sum % 1000000);
    }
}
