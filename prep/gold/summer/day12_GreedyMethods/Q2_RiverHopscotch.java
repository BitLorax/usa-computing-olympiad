package day12_GreedyMethods;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q2_RiverHopscotch {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int len = Integer.parseInt(st.nextToken());
        int rockCount = Integer.parseInt(st.nextToken());
        int removeCount = Integer.parseInt(st.nextToken());
        int[] rockLocs = new int[rockCount + 2];
        for (int i = 1; i <= rockCount; i++) {
            rockLocs[i] = Integer.parseInt(in.readLine());
        }
        rockLocs[0] = 0;
        rockLocs[rockCount + 1] = len;
        Arrays.sort(rockLocs);

        int lo = 1;
        int hi = 1000000000;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            System.out.println(lo + " " + mid + " " + hi);
            if (removeCount >= jump(rockLocs, mid)) lo = mid + 1;
            else hi = mid;
        }
        System.out.println(jump(rockLocs, lo));
    }
    private static int jump(int[] rockLocs, int jumpSize) {
        int removed = 0;
        int pos = 0;
        for (int i = 1; i < rockLocs.length; i++) {
            if (rockLocs[i] - pos < jumpSize) {
                removed++;
                i++;
            }
            else {
                pos = rockLocs[i];
            }
        }
        return removed;
    }
}
