package day3_DataStructures;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q7_Sunscreen {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int lotionCount = Integer.parseInt(st.nextToken());
        Cow[] cows = new Cow[cowCount]; //only maximum matters
        ArrayList<Integer> lotions = new ArrayList<>();
        for (int i = 0; i < cowCount; i++) {
            st = new StringTokenizer(in.readLine());
            cows[i] = new Cow(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(cows);
        for (int i = 0; i < lotionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int spf = Integer.parseInt(st.nextToken());
            int amt = Integer.parseInt(st.nextToken());
            for (int j = 0; j < amt; j++) {
                lotions.add(spf);
            }
        }
        Collections.sort(lotions);
        boolean[] covered = new boolean[cowCount];
        int protectedCows = 0;
        for (int spf : lotions) {
            int cow = -1;
            for (int i = 0; i < cowCount; i++) {
                if (cows[i].start <= spf && cows[i].end >= spf && !covered[i]) {
                    cow = i;
                    break;
                }
            }
            if (cow != -1) {
                protectedCows++;
                covered[cow] = true;
            }
        }
        System.out.println(protectedCows);
    }
    static class Cow implements Comparable<Cow> {
        int start;
        int end;
        Cow (int s, int e) {
            start = s;
            end = e;
        }
        public int compareTo(Cow a) {
            return this.end - a.end;
        }
    }
}
