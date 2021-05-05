package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q3_CountingHaybales {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int haybales = Integer.parseInt(st.nextToken());
        int queryCount = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        int[] pos = new int[haybales];
        for (int i = 0; i < haybales; i++) {
            pos[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(pos);
        for (int i = 0; i < queryCount; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int startFind = Arrays.binarySearch(pos, start);
            int diff = 0;
            if (startFind < 0) {
                startFind = (startFind + 1) * -1;
            } else {
                startFind++; //include itself
                diff++;
            }
            int endFind = Arrays.binarySearch(pos, end);
            if (endFind < 0) {
                endFind = (endFind + 1) * -1;
            } else {
                endFind++; //include itself
            }
            diff += endFind - startFind;
            System.out.println(diff);
        }
    }
}
