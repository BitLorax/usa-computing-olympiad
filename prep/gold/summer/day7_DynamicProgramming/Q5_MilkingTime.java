package day7_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q5_MilkingTime {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int timeEnd = Integer.parseInt(st.nextToken());
        int intervalCount = Integer.parseInt(st.nextToken());
        int restTime = Integer.parseInt(st.nextToken());
        Interval[] intervalInfo = new Interval[intervalCount];
        for (int i = 0; i < intervalCount; i++) {
            st = new StringTokenizer(in.readLine());
            intervalInfo[i] = new Interval(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(intervalInfo);
        int[] states = new int[intervalCount];
        for (int i = 0; i < intervalCount; i++) states[i] = intervalInfo[i].eff;
        for (int i = 0; i < intervalCount; i++) {
            for (int j = i + 1; j < intervalCount; j++) {
                if (intervalInfo[i].end + restTime <= intervalInfo[j].start) states[j] = Math.max(states[j], states[i] + intervalInfo[j].eff);
            }
        }
        int max = 0;
        for (int i : states) max = Math.max(max, i);
        System.out.println(max);
    }
    static class Interval implements Comparable<Interval>{
        int start, end, eff;
        Interval(int s, int e, int eff) {
            start = s;
            end = e;
            this.eff = eff;
        }
        public int compareTo(Interval a) {
            return this.start - a.start;
        }
    }
}
