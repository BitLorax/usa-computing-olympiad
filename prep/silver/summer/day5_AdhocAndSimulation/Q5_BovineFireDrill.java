package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q5_BovineFireDrill {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        int[] cows = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = i + 1;
        }
        boolean[] moved = new boolean[cowCount];
        int currCow = 1;
        int newCow = 0;
        int currChair = 0;
        cows[currChair] = -1; //cow 1 gets up
        moved[currCow - 1] = true;
        while (true) {
            currChair = addChairs(currChair, currCow, cowCount);
            if (currChair == 0) {
                break;
            }
            newCow = cows[currChair];
            if (moved[newCow - 1]) {
                break;
            }
            cows[currChair] = currCow;
            moved[newCow - 1] = true;
            currCow = newCow;
        }
        System.out.println(currCow);
    }
    private static int addChairs(int curr, int increase, int len) {
        if (curr + increase >= len) {
            return curr + increase - len;
        }
        return curr + increase;
    }
}
