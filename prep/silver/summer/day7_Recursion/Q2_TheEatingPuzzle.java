package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q2_TheEatingPuzzle {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int limit = Integer.parseInt(st.nextToken());
        int bucketCount = Integer.parseInt(st.nextToken());
        int[] buckets = new int[bucketCount];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(buckets);
        boolean[] eaten = new boolean[bucketCount];
        int ans = getMaxFeed(limit, 0, buckets, eaten, 0);
        System.out.println(ans);
    }
    private static int getMaxFeed(int limit, int currFeed, int[] buckets, boolean[] eaten, int maxFeed) {
        for (int i = 0; i < buckets.length; i++) {
            boolean[] newEaten = eaten.clone();
            int newCurrFeed = currFeed;
            if (!eaten[i]) {
                if (newCurrFeed + buckets[i] < limit) {
                    newCurrFeed += buckets[i];
                    newEaten[i] = true;
                    maxFeed = Math.max(getMaxFeed(limit, newCurrFeed, buckets, newEaten, maxFeed), maxFeed);
                } else {
                    maxFeed = Math.max(newCurrFeed, maxFeed);
                    break;
                }
            }
        }
        return maxFeed;
    }
}
