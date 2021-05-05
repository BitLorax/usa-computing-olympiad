package day13_ComputationalGeometry;

import java.io.*;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q4_CitySkyline {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int changeCount = Integer.parseInt(st.nextToken());
        int wide = Integer.parseInt(st.nextToken());
        int tallest = 0;
        ChangePoint[] changePoints = new ChangePoint[changeCount + 1];
        for (int i = 0; i < changeCount; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            tallest = Math.max(tallest, height);
            changePoints[i] = new ChangePoint(x, height);
        }
        changePoints[changeCount] = new ChangePoint(wide, 0);
        Arrays.sort(changePoints);
        Stack<Integer> buildingHeights = new Stack<>();
        int buildingCount = 0;
        for (int i = 0; i <= changeCount; i++) {
            ChangePoint currChange = changePoints[i];
            while (buildingHeights.size() > 0 && buildingHeights.peek() >= currChange.height) {
                if (buildingHeights.pop() != currChange.height) buildingCount++;
            }
            buildingHeights.add(currChange.height);
        }
        System.out.println(buildingCount);
    }
    static class ChangePoint implements Comparable<ChangePoint> {
        int x;
        int height;
        ChangePoint(int x, int height) {
            this.x = x;
            this.height = height;
        }
        public int compareTo(ChangePoint a) {
            return this.x - a.x;
        }
    }
}
