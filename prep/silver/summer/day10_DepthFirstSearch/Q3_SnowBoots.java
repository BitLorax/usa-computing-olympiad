package day10_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q3_SnowBoots {
    private static int[] path;
    private static int bootCount;
    private static int[][] boots;
    private static int minBootsUsed = Integer.MAX_VALUE;
    private static boolean[][] previousStates;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int pathLen = Integer.parseInt(st.nextToken());
        bootCount = Integer.parseInt(st.nextToken());
        path = new int[pathLen];
        previousStates = new boolean[bootCount][pathLen];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < pathLen; i++) {
            path[i] = Integer.parseInt(st.nextToken());
        }
        boots = new int[bootCount][2];
        for (int i = 0; i < bootCount; i++) {
            st = new StringTokenizer(in.readLine());
            boots[i][0] = Integer.parseInt(st.nextToken());
            boots[i][1] = Integer.parseInt(st.nextToken());
        }
        tryPath(0, 0);
        System.out.println(minBootsUsed);
    }
    private static void tryPath(int boot, int currPos) {
        if (currPos == path.length - 1) {
            minBootsUsed = Math.min(boot, minBootsUsed);
            return;
        }
        if (previousStates[boot][currPos]) {
            return;
        }
        previousStates[boot][currPos] = true;
        int currStrength = boots[boot][0];
        int currAgility = boots[boot][1];
        for (int i = 1; i <= currAgility; i++) {
            if (currPos + i < path.length) {
                if (currStrength >= path[currPos + i]) {
                    tryPath(boot, currPos + i);
                }
            } else {
                break;
            }
        }
        for (int i = 1; i < bootCount - 1 - boot; i++) {
            if (boots[boot + i][0] >= path[currPos]) { //able to change
                tryPath(boot + i, currPos);
            }
        }
    }
}
