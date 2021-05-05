package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q4_LongDistanceRacing {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int limit = Integer.parseInt(st.nextToken());
        int pathLen = Integer.parseInt(st.nextToken());
        int uphill = Integer.parseInt(st.nextToken());
        int flat = Integer.parseInt(st.nextToken());
        int downhill = Integer.parseInt(st.nextToken());

        int totalTime = 0;
        int unitsPassed = 0;
        for (int i = 0; i < pathLen; i++) {
            String terrain = in.readLine();
            if (totalTime + getTime(terrain, uphill, flat, downhill) > limit) {
                break;
            }
            totalTime += getTime(terrain, uphill, flat, downhill);
            unitsPassed++;
        }
        System.out.println(unitsPassed);
    }
    private static int getTime(String terrain, int up, int flat, int down) {
        switch (terrain) {
            case "u": return up + down;
            case "d": return down + up;
            case "f": return 2 * flat;
            default: return -1;
        }
    }
}
