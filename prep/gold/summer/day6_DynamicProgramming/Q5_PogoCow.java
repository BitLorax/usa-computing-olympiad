package day6_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Q5_PogoCow {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int targetCount = Integer.parseInt(in.readLine());
        Target[] targetInfo = new Target[targetCount];
        for (int i = 0; i < targetCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            targetInfo[i] = new Target(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(targetInfo, new TargetAscending());
        int maxPts = 0;
        int[][] states = new int[targetCount][targetCount];
        for (int i = targetCount - 1; i >= 0; i--) {
            int k = targetCount; //possible "next" location, j -> i -> k -> some other points
            int max = 0;
            for (int j = 0; j <= i; j++) { //start location, j -> i -> end, not including i and j
                while (k - 1 > i && Math.abs(targetInfo[j].pos - targetInfo[i].pos) <= Math.abs(targetInfo[i].pos - targetInfo[k - 1].pos)) {
                    k--;
                    max = Math.max(max, targetInfo[k].val + states[i][k]); //don't include key points to avoid overcount *
                }
                states[j][i] = max;
            }
            maxPts = Math.max(maxPts, targetInfo[i].val + max);
        }
        Arrays.sort(targetInfo, new TargetDescending());
        states = new int[targetCount][targetCount];
        for (int i = targetCount - 1; i >= 0; i--) {
            int k = targetCount; //possible "next" location, j -> i -> k -> some other points
            int max = 0;
            for (int j = 0; j <= i; j++) { //start location, j -> i -> end, not including i and j
                while (k - 1 > i && Math.abs(targetInfo[j].pos - targetInfo[i].pos) <= Math.abs(targetInfo[i].pos - targetInfo[k - 1].pos)) {
                    k--;
                    max = Math.max(max, targetInfo[k].val + states[i][k]); //don't include key points to avoid overcount *
                }
                states[j][i] = max;
            }
            maxPts = Math.max(maxPts, targetInfo[i].val + max);
        }
        System.out.println(maxPts);
    }
    static class Target {
        int pos;
        int val;
        Target(int p, int v) {
            pos = p;
            val = v;
        }
    }
    static class TargetAscending implements Comparator<Target> {
        public int compare(Target a, Target b) {
            return a.pos - b.pos;
        }
    }
    static class TargetDescending implements Comparator<Target> {
        public int compare(Target a, Target b) {
            return b.pos - a.pos;
        }
    }
}
/*
To avoid overcount, do not count i and j
When calculating j -> i -> k -> other points, add on states[i][k], then k bc it isn't a vital point anymore
 */
