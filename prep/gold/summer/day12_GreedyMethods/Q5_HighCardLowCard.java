package day12_GreedyMethods;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Q5_HighCardLowCard {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cardCount = Integer.parseInt(in.readLine());
        int[] oppoHand = new int[cardCount];
        boolean[] myCards = new boolean[cardCount * 2];
        for (int i = 0; i < cardCount; i++) {
            int j = Integer.parseInt(in.readLine());
            oppoHand[i] = j;
            myCards[j - 1] = true;
        }
        int[] myHand = new int[cardCount];
        int l = 0;
        for (int i = 0; i < cardCount * 2; i++) {
            if (!myCards[i]) myHand[l++] = i + 1;
        }
        Arrays.sort(myHand);
        System.out.println(play(Arrays.copyOfRange(myHand, cardCount / 2, cardCount), Arrays.copyOfRange(oppoHand, 0, cardCount / 2), true) + play(Arrays.copyOfRange(myHand, 0, cardCount / 2), Arrays.copyOfRange(oppoHand, cardCount / 2, cardCount), false));
    }
    private static int play(int[] myCards, int[] oppoCards, boolean greaterWins) {
        int wins = 0;
        boolean[] myCardsUsed = new boolean[myCards.length];
        for (int i = 0; i < oppoCards.length; i++) {
            int j = Arrays.binarySearch(myCards, oppoCards[i]);
            if (greaterWins) {
                if (j >= 0) j++;
                else j = (j + 1) * -1;
            } else {
                if (j >= 0) j--;
                else j = (j + 1) * -1 - 1;
            }
            if (greaterWins) while (j < myCards.length && myCardsUsed[j]) j++;
            else while (j >= 0 && myCardsUsed[j]) j--;
            if (greaterWins) {
                if (j >= myCards.length) { //can't win
                    int k = 0;
                    while (myCardsUsed[k]) k++; //sacrifice lowest card
                    myCardsUsed[k] = true;
                } else {
                    wins++;
                    myCardsUsed[j] = true;
                }
            } else {
                if (j < 0) { //can't win
                    int k = myCards.length - 1;
                    while (myCardsUsed[k]) k--;
                    myCardsUsed[k] = true;
                } else {
                    wins++;
                    myCardsUsed[j] = true;
                }
            }
        }
        return wins;
    }
}
