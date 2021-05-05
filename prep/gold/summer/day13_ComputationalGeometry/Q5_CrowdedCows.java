package day13_ComputationalGeometry;

import java.io.*;
import java.util.Arrays;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Q5_CrowdedCows {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int distance = Integer.parseInt(st.nextToken());
        Cow[] cowInfo = new Cow[cowCount];
        for (int i = 0; i < cowCount; i++) {
            st = new StringTokenizer(in.readLine());
            cowInfo[i] = new Cow(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(cowInfo);
        TreeSet<Long> rightWindow = new TreeSet<>();
        TreeSet<Long> leftWindow = new TreeSet<>();
        int rightPos = 0;
        int leftPos = 0;
        int crowded = 0;
        for (int ii = 0; ii < cowCount; ii++) {
            Cow currCow = cowInfo[ii];
            while (rightPos < cowCount && Math.abs(currCow.x - cowInfo[rightPos].x) <= distance) {
                rightWindow.add(cowInfo[rightPos].hash());
                rightPos++;
            }
            rightWindow.remove(currCow.hash());
            leftWindow.add(currCow.hash());
            while (leftPos < cowCount && Math.abs(currCow.x - cowInfo[leftPos].x) > distance) {
                leftWindow.remove(cowInfo[leftPos].hash());
                leftPos++;
            }
            if (rightWindow.size() > 0 && leftWindow.size() > 0) {
                long rightMax = rightWindow.last() / 1000000000;
                long leftMax = leftWindow.last() / 1000000000;
                if (rightMax >= (long)(currCow.height * 2)) {
                    if (leftMax >= (long)(currCow.height * 2)) {
                        crowded++;
                    }
                }
            }
        }
        System.out.println(crowded);
    }
    static class Cow implements Comparable<Cow> {
        int x;
        int height;
        Cow (int x, int height) {
            this.x = x;
            this.height = height;
        }
        public int compareTo(Cow a) {
            return this.x - a.x;
        }
        long hash() {return x + height * 1000000000L;};
    }
}
