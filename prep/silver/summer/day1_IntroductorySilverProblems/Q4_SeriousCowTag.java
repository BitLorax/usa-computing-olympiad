package day1_IntroductorySilverProblems;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Q4_SeriousCowTag {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cowCount = Integer.parseInt(in.nextLine());
        int[][] coords = new int[2][cowCount];
        int cowsRemaining = cowCount;
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.nextLine());
            coords[0][i] = Integer.parseInt(st.nextToken());
            coords[1][i] = Integer.parseInt(st.nextToken());
        }
        boolean[] cowStatus = new boolean[cowCount];
        for (int i = 0; i < cowStatus.length; i++) {
            cowStatus[i] = true;
        }
        int cowTurn = 0;
        while (cowsRemaining != 1) {
            if (cowStatus[cowTurn]) {
                cowStatus[findNearestCow(coords, cowTurn, cowStatus)] = false;
                cowsRemaining--;
            }
            cowTurn++;
            if (cowTurn >= cowStatus.length) {
                cowTurn -= cowStatus.length;
            }
        }
        System.out.println(findLastCow(cowStatus) + 1);
    }
    private static int findNearestCow(int[][] coords, int currCow, boolean[] cowStatus) {
        int cowX = coords[0][currCow];
        int cowY = coords[1][currCow];
        int closestCow = -1;
        double closestLen = -1;
        for (int i = 0; i < cowStatus.length; i++) {
            if (cowStatus[i]) {
                if ((dist(cowX, cowY, coords[0][i], coords[1][i]) < closestLen || closestLen == -1) && dist(cowX, cowY, coords[0][i], coords[1][i]) != 0) {
                    closestCow = i;
                    closestLen = dist(cowX, cowY, coords[0][i], coords[1][i]);
                }
            }
        }
        return closestCow;
    }
    private static double dist(int x1, int y1, int x2, int y2) {
        return (Math.sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }
    private static int findLastCow(boolean[] cowStatus) {
        for (int i = 0; i < cowStatus.length; i++) {
            if (cowStatus[i]) {
                return i;
            }
        }
        return -1;
    }
}
