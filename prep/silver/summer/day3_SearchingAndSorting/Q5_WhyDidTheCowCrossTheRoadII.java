package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q5_WhyDidTheCowCrossTheRoadII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int signalCount = Integer.parseInt(st.nextToken());
        int minBlock = Integer.parseInt(st.nextToken());
        int brokenCount = Integer.parseInt(st.nextToken());
        int[] brokenSignals = new int[brokenCount];
        for (int i = 0; i < brokenCount; i++) {
            brokenSignals[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(brokenSignals);
        int[] signals = new int[signalCount]; //+1 for working, 0 for broken
        for (int i = 0; i < signalCount; i++) {
            if (Arrays.binarySearch(brokenSignals, i + 1) < 0) {
                signals[i] = 1;
            } else {
                signals[i] = 0;
            }
        }
        int currSum = 0;
        int minFix = minBlock;
        for (int i = 0; i < minBlock; i++) {
            currSum += signals[i];
        } //find currSum when window is at 0
        for (int i = 0; i < signalCount - minBlock; i++) {
            if (i != 0) {
                currSum -= signals[i - 1];
                currSum += signals[i + minBlock - 1];
            }
            minFix = Math.min(minFix, minBlock - currSum);
        }

        System.out.println(minFix);
    }
}
