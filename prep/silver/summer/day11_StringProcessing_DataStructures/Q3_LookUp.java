package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Q3_LookUp {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = Integer.parseInt(in.readLine());
        }
        Stack<Integer> cowsNotLooking = new Stack<>();
        int[] indexes = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            int height = cows[i];
            if (!cowsNotLooking.empty() && height > cows[cowsNotLooking.peek()]) {
                while (!cowsNotLooking.empty() && height > cows[cowsNotLooking.peek()]) {
                    indexes[cowsNotLooking.peek()] = i + 1;
                    cowsNotLooking.pop();
                }
            }
            cowsNotLooking.push(i);
        }
        for (int index : indexes) {
            System.out.println(index);
        }
    }
}
