package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q4_HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int rounds = Integer.parseInt(in.readLine());
        int[] firstChoiceWins = new int[3];
        int[] secondChoiceWins = new int[3];
        int[] moves = new int[rounds];
        for (int i = 0; i < rounds; i++) {
            int move = moveToInt(in.readLine());
            moves[i] = move;
            secondChoiceWins[getDefeater(move)]++;
        }
        int totalWins = 0;
        int maxWins = 0;
        for (int i = 0; i < rounds; i++) {
            int move = moves[i];
            firstChoiceWins[getDefeater(move)]++;
            secondChoiceWins[getDefeater(move)]--;
            totalWins = getMaxVal(firstChoiceWins) + getMaxVal(secondChoiceWins);
            maxWins = Math.max(totalWins, maxWins);
        }
        System.out.println(maxWins);
    }
    private static int moveToInt(String move) {
        switch (move) {
            case "P": return 0;
            case "H": return 1;
            case "S": return 2;
            default: return -1;
        }
    }
    private static int getDefeater(int move) {
        if (move - 1 == -1) {
            return 2;
        }
        return move - 1;
    }
    private static int getMaxVal(int[] lst) {
        int max = 0;
        for (int val : lst) {
            max = Math.max(val, max);
        }
        return max;
    }
}
