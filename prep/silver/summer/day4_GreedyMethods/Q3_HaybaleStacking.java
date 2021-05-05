package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q3_HaybaleStacking {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int stackCount = Integer.parseInt(st.nextToken());
        int commandCount = Integer.parseInt(st.nextToken());
        int[] stackChanges = new int[stackCount];
        for (int i = 0; i < commandCount; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken()) - 1;
            int end = Integer.parseInt(st.nextToken());
            stackChanges[start] += 1;
            if (end < stackCount) {
                stackChanges[end] -= 1;
            }
        }
        int[] stackHeights = new int[stackCount];
        int sum = 0;
        for (int i = 0; i < stackCount; i++) {
            sum += stackChanges[i];
            stackHeights[i] = sum;
        }
        Arrays.sort(stackHeights);
        System.out.println(stackHeights[(stackCount - 1) / 2]);
    }
}
