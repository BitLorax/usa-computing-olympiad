package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q2_DiningCows {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = Integer.parseInt(in.readLine());
        }
        int change = 0;
        int minChange = 0;

        for (int i = 0; i < cowCount; i++) { //start with changing everything to 2
            if (cows[i] == 1) {
                change++;
            }
            minChange = change;
        }

        for (int i = 0; i < cowCount; i++) {
            if (cows[i] != 1) {
                change++;
            } else {
                change--;
            }
            minChange = Math.min(minChange, change);
        }
        System.out.println(minChange);
    }
}
