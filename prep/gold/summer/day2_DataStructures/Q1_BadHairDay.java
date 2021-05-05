package day2_DataStructures;

import java.io.*;
import java.util.Stack;

public class Q1_BadHairDay {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = Integer.parseInt(in.readLine());
        }
        Stack<Integer> canBeSeen = new Stack<>();
        long totalSeen = 0;
        int[] cowsSeen = new int[cowCount];
        for (int i = cowCount - 1; i >= 0; i--) {
            while (!canBeSeen.isEmpty() && cows[i] > cows[canBeSeen.peek()]) {
                cowsSeen[i] += cowsSeen[canBeSeen.peek()] + 1;
                totalSeen += cowsSeen[canBeSeen.pop()] + 1;
            }
            canBeSeen.add(i);
        }
        System.out.println(totalSeen);
    }
}
