package day_15_Final;

import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.concurrent.DelayQueue;

public class Q1_BestCowLine {
    private static char[] cows;
    private static String[][] states;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        cows = new char[cowCount];
        states = new String[cowCount][cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = in.readLine().charAt(0);
        }
        String ans = "";
        int left = 0;
        int right = cowCount - 1;
        while (left != right) {
            if (cows[left] < cows[right]) {
                ans += cows[left];
                left++;
            } else if (cows[left] > cows[right]) {
                ans += cows[right];
                right--;
            } else {
                int leftTemp = left + 1;
                int rightTemp  = right - 1;
                while (leftTemp < rightTemp && cows[leftTemp] == cows[rightTemp]) {
                    leftTemp++;
                    rightTemp--;
                }
                if (cows[leftTemp] < cows[rightTemp]) {
                    ans += cows[left];
                    left++;
                } else {
                    ans += cows[right];
                    right--;
                }
            }
        }
        ans += cows[right];
        int i = 0;
        while (i < ans.length()) {
            if (i % 80 == 0 && i != 0) System.out.println();
            System.out.print(ans.charAt(i));
            i++;
        }
    }
    private static Deque<Character> clone(Deque<Character> in) {
        Deque<Character> out = new LinkedList<>();
        for (Character a : in) {
            out.add(a);
        }
        return out;
    }
    /*
    private static String arrangeCows(int start, int end) {
        if (states[start][end] != null) return states[start][end];
        if (start == end) {
            states[start][end] = "" + cows[start];
            return states[start][end];
        }
        String ansOne = arrangeCows(start + 1, end);
        String ansTwo = arrangeCows(start, end - 1);
        if ((cows[start] + ansOne).compareTo(cows[end] + ansTwo) < 0) states[start][end] = cows[start] + ansOne;
        else states[start][end] = cows[end] + ansTwo;
        return states[start][end];
    }
    */
    /*
    private static char toChar(int a) {
        switch (a) {
            case 65: return 'A';
            case 66: return 'B';
            case 67: return 'C';
            case 68: return 'D';
            case 69: return 'E';
            case 70: return 'F';
            case 71: return 'G';
            case 72: return 'H';
            case 73: return 'I';
            case 74: return 'J';
            case 75: return 'K';
            case 76: return 'L';
            case 77: return 'M';
            case 78: return 'N';
            case 79: return 'O';
            case 80: return 'P';
            case 81: return 'Q';
            case 82: return 'R';
            case 83: return 'S';
            case 84: return 'T';
            case 85: return 'U';
            case 86: return 'V';
            case 87: return 'W';
            case 88: return 'X';
            case 89: return 'Y';
            case 90: return 'Z';
            default: return 'n';
        }
    }
    */
}
