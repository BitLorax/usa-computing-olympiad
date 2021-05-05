package day6_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q3_GrazingOnTheRun {
    private static int[][][] states;
    private static int[][][] stalenessEaten;
    private static int[] clumpLocs;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int clumpCount = Integer.parseInt(st.nextToken());
        int startPos = Integer.parseInt(st.nextToken());
        clumpLocs = new int[clumpCount];
        for (int i = 0; i < clumpCount; i++) clumpLocs[i] = Integer.parseInt(in.readLine());
        Arrays.sort(clumpLocs);
        states = new int[clumpCount][clumpCount][2];
        stalenessEaten = new int[clumpCount][clumpCount][2];
        for (int i = 0; i < clumpCount; i++) {
            for (int j = 0; j < clumpCount; j++) {
                states[i][j][0] = 1000000000;
                states[i][j][1] = 1000000000;
                stalenessEaten[i][j][0] = 1000000000;
                stalenessEaten[i][j][1] = 1000000000;
            }
        }
        int pos = Arrays.binarySearch(clumpLocs, startPos);
        if (pos < 0) {
            pos = (pos + 1) * -1;
            int left = pos - 1;
            int right = pos;
            if (left >= 0) {
                goToClumps(left, left, 0, Math.abs(startPos - clumpLocs[left]), 0);
                goToClumps(left, left, 1, Math.abs(startPos - clumpLocs[left]), 0);
            }
            if (right < clumpCount) {
                goToClumps(right, right, 0, Math.abs(startPos - clumpLocs[right]), 0);
                goToClumps(right, right, 1, Math.abs(startPos - clumpLocs[right]), 0);
            }
        } else {
            goToClumps(pos, pos, 0, 0, 0);
            goToClumps(pos, pos, 1, 0, 0);
        }
        System.out.println(Math.min(stalenessEaten[0][clumpCount - 1][0], stalenessEaten[0][clumpCount - 1][1]));
    }
    private static void goToClumps(int left, int right, int pos, int staleness, int eaten) {
        eaten += staleness;
        if (stalenessEaten[left][right][pos] <= eaten) return;
        states[left][right][pos] = staleness;
        stalenessEaten[left][right][pos] = eaten;
        //move right
        if (left > 0) {
            if (pos == 0) goToClumps(left - 1, right, 0, staleness + Math.abs(clumpLocs[left] - clumpLocs[left - 1]), eaten); //from this left
            else goToClumps(left - 1, right, 0, staleness + Math.abs(clumpLocs[right] - clumpLocs[left - 1]), eaten); //from this right
        }
        //move right
        if (right < clumpLocs.length - 1) {
            if (pos == 1) {
                goToClumps(left, right + 1, 1, staleness + Math.abs(clumpLocs[right] - clumpLocs[right + 1]), eaten); //from this right
            } else {
                goToClumps(left, right + 1, 1, staleness + Math.abs(clumpLocs[left] - clumpLocs[right + 1]), eaten); //from this left
            }
        }
    }
}
