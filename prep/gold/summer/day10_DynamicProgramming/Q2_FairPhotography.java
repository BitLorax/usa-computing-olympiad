package day10_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q2_FairPhotography {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Cow[] cows = new Cow[cowCount];
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            cows[i] = new Cow(Integer.parseInt(st.nextToken()), toInt(st.nextToken().charAt(0)));
        }
        Arrays.sort(cows);
        int[] sums = new int[cowCount];
        int sum = 0;
        for (int i = 0; i < cowCount; i++) {
            sum += cows[i].type;
            sums[i] = sum;
        }
        int maxDist = 0;
        for (int i = 0; i < cowCount; i++) {
            for (int j = 0; j < i; j++) {
                if (i % 2 == 1 && cows[i].pos > 0) {
                    maxDist = Math.max(maxDist, cows[i].pos - cows[0].pos);
                    break;
                }
                if (j % 2 != i % 2) continue;
                if (sums[i] >= sums[j]) {
                    maxDist = Math.max(maxDist, cows[i].pos - cows[j + 1].pos);
                    break;
                }
            }
        }
        System.out.println(maxDist);
    }
    private static int toInt(char in) {
        if (in == 'W') return 1;
        return -1;
    }
    static class Cow implements Comparable<Cow> {
        int pos;
        int type;
        Cow (int p, int t) {
            pos = p;
            type = t;
        }
        public int compareTo(Cow a) {
            return this.pos - a.pos;
        }
    }
}
