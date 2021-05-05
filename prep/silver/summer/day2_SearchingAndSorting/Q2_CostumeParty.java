package day2_SearchingAndSorting;

import java.util.*;

public class Q2_CostumeParty {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int costumeLen = Integer.parseInt(st.nextToken());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = Integer.parseInt(in.nextLine());
        }
        int total = 0;
        for (int i = 0; i < cowCount; i++) {
            for (int j = i + 1; j < cowCount; j++) {
                if (cows[i] + cows[j] <= costumeLen) {
                    total++;
                }
            }
        }
        System.out.println(total);
        // Binary search finds first appearance of element, can't accurately find # of elements before num
        /*
        Arrays.sort(cows);
        long total = 0;
        for (int i = 0; i < cowCount; i++) {
            int maxLen = costumeLen - cows[i];
            int cutoff = Arrays.binarySearch(cows, maxLen);
            if (cutoff < 0) {
                cutoff = (cutoff + 1) * -1;
            } else {
                cutoff++; //count itself
            }
            if (maxLen >= cows[i]) {
                cutoff -= 1;
            }
            total += cutoff;
        }
        System.out.println(total / 2);
        */
    }
}

