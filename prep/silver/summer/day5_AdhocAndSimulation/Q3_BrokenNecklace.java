package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q3_BrokenNecklace {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        char[] necklace = new char[len];
        String necklaceIn = in.readLine();
        for (int i = 0; i < len; i++) {
            necklace[i] = necklaceIn.charAt(i);
        }
        int maxBeads = 0;
        int totalBeads = 2;
        for (int i = 0; i < len; i++) { //every breakpoint
            char[] necklaceCopy = necklace.clone();
            int leftIndex = getPrevIndex(i, len);
            int rightIndex = i;
            char colorL = necklaceCopy[leftIndex];
            char colorR = necklaceCopy[rightIndex];
            necklaceCopy[leftIndex] = 'N'; //take out
            necklaceCopy[rightIndex] = 'N';

            boolean sameColor = true;
            int bead = 1;
            while (sameColor) { //for left
                leftIndex = getPrevIndex(leftIndex, len); //bead testing
                char currBead = necklaceCopy[leftIndex];
                if ((colorL == 'w' && currBead == 'r') || (colorL == 'w' && currBead == 'b') || colorL == currBead || currBead == 'w') {
                    bead++;
                    necklaceCopy[leftIndex] = 'N';
                    if (colorL == 'w') {
                        colorL = currBead;
                    }
                } else {
                    sameColor = false;
                }
            }
            bead++;
            sameColor = true;
            while (sameColor) { //for right
                rightIndex = getNextIndex(rightIndex, len);
                char currBead = necklaceCopy[rightIndex];
                if ((colorR == 'w' && currBead == 'r') || (colorR == 'w' && currBead == 'b') || colorR == currBead || currBead == 'w') {
                    bead++;
                    necklaceCopy[rightIndex] = 'N';
                    if (colorR == 'w') {
                        colorR = currBead;
                    }
                } else {
                    sameColor = false;
                }
            }
            totalBeads = Math.max(totalBeads, bead);
        }
        System.out.println(totalBeads);
    }
    private static int getPrevIndex(int currIndex, int len) {
        if (currIndex - 1 < 0) {
            return len - 1;
        }
        return currIndex - 1;
    }
    private static int getNextIndex(int currIndex, int len) {
        if (currIndex + 1 >= len) {
            return 0;
        }
        return currIndex + 1;
    }
}
