package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q2_CleaningTheDishes {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> toBeWashed = new Stack<>();
        Stack<Integer> toBeDried = new Stack<>();
        Stack<Integer> finished = new Stack<>();
        int dishCount = Integer.parseInt(in.readLine());
        for (int i = 0; i < dishCount; i++) {
            toBeWashed.add(dishCount - i);
        }
        while (finished.size() != dishCount) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int cow = Integer.parseInt(st.nextToken());
            int dishes = Integer.parseInt(st.nextToken());
            for (int i = 0; i < dishes; i++) {
                if (cow == 1) {
                    toBeDried.add(toBeWashed.pop());
                } else if (cow == 2) {
                    finished.add(toBeDried.pop());
                }
            }
        }
        for (int i = dishCount - 1; i >= 0; i--) {
            System.out.println(finished.get(i));
        }
    }
}
