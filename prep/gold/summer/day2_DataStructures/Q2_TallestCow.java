package day2_DataStructures;

import java.io.*;
import java.util.*;

public class Q2_TallestCow {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int greatestIndex = Integer.parseInt(st.nextToken());
        int greatestVal = Integer.parseInt(st.nextToken());
        int compareCount = Integer.parseInt(st.nextToken());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = greatestVal;
        }
        //Map<Integer, Integer> cowSees = new HashMap<>(); //i sees j
        Queue<Sees> cowSees = new LinkedList<>();
        for (int i = 0; i < compareCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            cowSees.add(new Sees(j, k));
        }
        while (!cowSees.isEmpty()) {
            Sees pair = cowSees.remove();
            if (cows[pair.end] < cows[pair.start]) { //check end >= start
                cows[pair.start] = cows[pair.end];
            }
            //check mid < start
            int k;
            int l;
            if (pair.start < pair.end) {
                k = pair.start + 1;
                l = pair.end;
            }
            else {
                k = pair.end + 1;
                l = pair.start;
            }
            int max = 0;
            for (int i = k; i < l; i++) {
                max = Math.max(cows[i], max);
            }
            for (int i = k; i < l; i++) {
                cows[i] -= (max - cows[pair.start] + 1);
            }
        }
        for (int i : cows) {
            System.out.println(i);
        }
    }
    static class Sees {
        int start;
        int end;
        Sees(int s, int e) {
            this.start = s;
            this.end = e;
        }
    }
}
