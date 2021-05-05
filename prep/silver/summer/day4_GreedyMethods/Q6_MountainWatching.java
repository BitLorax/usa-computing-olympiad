package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q6_MountainWatching {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int measurementCount = Integer.parseInt(in.readLine());
        int change; //up or down (+ or -)
        int width = 1;
        int maxWidth = 0;

        int oldHeight = Integer.parseInt(in.readLine());
        int oldChange = 1;
        int flat = 1;
        for (int i = 1; i < measurementCount; i++) {
            int height = Integer.parseInt(in.readLine());
            change = height - oldHeight;
            if (oldChange < 0 && change > 0) { //end of mountain, if there is a "\[flat lines]/"
                maxWidth = Math.max(maxWidth, width);
                width = 1 + flat; //includes all previous flat points and this point
            } else {
                width++;
            }
            if (change != 0) { //no use if flat doesn't add to new mountain, so reset
                flat = 1;
                oldChange = change;
            } else {
                flat++; //part of new mountain
            }
            if (i == measurementCount - 1) {
                maxWidth = Math.max(maxWidth, width);
            } //calculate final mountain that is cut off
            oldHeight = height;
        }

        System.out.println(maxWidth);
    }
}
