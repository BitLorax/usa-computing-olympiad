package day15_Final;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q2_GoldilocksAndTheNCows {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int cold = Integer.parseInt(st.nextToken());
        int comfortable = Integer.parseInt(st.nextToken());
        int hot = Integer.parseInt(st.nextToken());

        ChangePoint[] changePoints = new ChangePoint[2 * cowCount];
        for (int i = 0; i < cowCount; i++) {
            st = new StringTokenizer(in.readLine());
            changePoints[i * 2] = new ChangePoint(Integer.parseInt(st.nextToken()), 1);
            changePoints[i * 2 + 1] = new ChangePoint(Integer.parseInt(st.nextToken()) + 1, -1);
        }
        Arrays.sort(changePoints);

        int coldCount = cowCount;
        int comfortableCount = 0;
        int hotCount = 0;
        int maxMilk = cowCount * cold;
        int index = 0;
        while (index < changePoints.length) {
            int currTemp = changePoints[index].temp;
            if (changePoints[index].mag == 1) {
                comfortableCount++;
                coldCount--;
            } else if (changePoints[index].mag == -1) {
                comfortableCount--;
                hotCount++;
            }
            while (++index < changePoints.length && changePoints[index].temp == currTemp) {
                if (changePoints[index].mag == 1) {
                    comfortableCount++;
                    coldCount--;
                } else if (changePoints[index].mag == -1) {
                    comfortableCount--;
                    hotCount++;
                }
            }
            maxMilk = Math.max(maxMilk, coldCount * cold + hotCount * hot + comfortableCount * comfortable);

        }
        System.out.println(maxMilk);
    }
    static class ChangePoint implements Comparable<ChangePoint> {
        int temp;
        int mag;
        ChangePoint(int time, int mag) {
            this.temp = time;
            this.mag = mag;
        }
        public int compareTo(ChangePoint a) {
            return temp - a.temp;
        }
    }
}
