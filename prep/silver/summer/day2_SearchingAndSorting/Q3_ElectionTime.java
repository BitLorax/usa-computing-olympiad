package day2_SearchingAndSorting;

import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Q3_ElectionTime {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int cowR1 = Integer.parseInt(st.nextToken());
        int cowR2 = Integer.parseInt(st.nextToken());
        Map<Integer, Integer> round1 = new TreeMap<>();
        Map<Integer, Integer> round2 = new TreeMap<>();

        for (int i = 1; i <= cowR1; i++) {
            st = new StringTokenizer(in.nextLine());
            round1.put(Integer.parseInt(st.nextToken()), i);
            round2.put(i, Integer.parseInt(st.nextToken()));
        }
        Object[] cows = round1.values().toArray();
        int[] cowsLeft = new int[cowR2];
        int winner = -1;
        int votes = 0;
        for (int i = 0; i < cowR2; i++) {
            int candidate = (int) cows[cows.length - 1 - i];
            if (round2.get(candidate) > votes) {
                winner = candidate;
                votes = round2.get(candidate);
            }
        }

        System.out.println(winner);
    }
}
