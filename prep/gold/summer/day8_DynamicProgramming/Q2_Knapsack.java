package day8_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q2_Knapsack {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int objectCount = Integer.parseInt(st.nextToken());
        int capacity = Integer.parseInt(st.nextToken());
        int[][] objectInfo = new int[objectCount][2];
        for (int i = 0; i < objectCount; i++) {
            st = new StringTokenizer(in.readLine());
            objectInfo[i][0] = Integer.parseInt(st.nextToken()); //size
            objectInfo[i][1] = Integer.parseInt(st.nextToken()); //value
        }
        int[] maxVals = new int[capacity + 1];
        for (int i = 1; i < capacity; i++) maxVals[i] = -1;
        for (int i = 0; i < objectCount; i++) {
            for (int j = capacity; j >= objectInfo[i][0]; j--) {
                if (maxVals[j - objectInfo[i][0]] != -1) maxVals[j] = Math.max(maxVals[j], maxVals[j - objectInfo[i][0]] + objectInfo[i][1]);
            }
        }
        int max = 0;
        for (int i : maxVals) max = Math.max(max, i);
        System.out.println(max);
    }
}
