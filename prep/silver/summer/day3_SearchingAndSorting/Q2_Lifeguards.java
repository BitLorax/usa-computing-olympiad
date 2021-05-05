package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q2_Lifeguards {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        TreeSet<Integer> activeCows = new TreeSet<>();
        //ArrayList<Integer> activeCows = new ArrayList<>();
        int cowCount = Integer.parseInt(in.readLine());
        ChangePoints[] changePoints = new ChangePoints[2 * cowCount];
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            changePoints[2 * i] = new ChangePoints(Integer.parseInt(st.nextToken()), i);
            changePoints[2 * i + 1] = new ChangePoints(Integer.parseInt(st.nextToken()), i);
        }
        Arrays.sort(changePoints);

        int[] cowTimeAlone = new int[cowCount];
        //int currLGCount = 0;
        int totalTime = 0;
        for (int i = 0; i < changePoints.length - 1; i++) {
            int currInterval = getIntervalLen(changePoints, i);
            ChangePoints currPoint = changePoints[i];
            //currLGCount += currPoint.change; //number of cows throughout ENTIRE interval
            if (activeCows.contains(currPoint.cow)) {
                activeCows.remove(currPoint.cow);
            } else {
                //activeCows.remove(activeCows.indexOf(currPoint.cow));
                activeCows.add(currPoint.cow);
            }
            if (activeCows.size() > 0) {
                totalTime += currInterval;
            } //update total time
            if (activeCows.size() == 1) { //Next one cannot be 1, therefore the alone time must be the interval
                cowTimeAlone[activeCows.first()] += currInterval;
            }
        }
        Arrays.sort(cowTimeAlone);
        System.out.println(totalTime - cowTimeAlone[0]);
    }
    private static int getIntervalLen(ChangePoints[] changePoints, int currIndex) { //returns length of interval of CG and the one AFTER it
        return changePoints[currIndex + 1].time - changePoints[currIndex].time;
    }
    static class ChangePoints implements Comparable<ChangePoints> {
        int time;
        int cow;
        ChangePoints(int time, int cow) {
            this.time = time;
            this.cow = cow;
        }
        public int compareTo(ChangePoints a) {
            return time - a.time;
        }
    }
}


