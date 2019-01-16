package gold.usaco2015;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class P1_HighCardLowCard {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/gold/resources2015/cardgame.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gold/resources2015/cardgame.out")));
        int cardCount = Integer.parseInt(in.readLine());
        int[] oppoHand = new int[cardCount];
        int[] sortedOppoHand = new int[cardCount];
        for (int i = 0; i < cardCount; i++) {
            int j = Integer.parseInt(in.readLine());
            oppoHand[i] = j;
            sortedOppoHand[i] = j;
        }
        Arrays.sort(sortedOppoHand);
        int[] hand = new int[cardCount];
        int index = 0;
        for (int i = 1; i <= cardCount * 2; i++) {
            if (Arrays.binarySearch(sortedOppoHand, i) < 0) {
                hand[index] = i;
                index++;
            }
        }
        Arrays.sort(hand);
        int wins = 0;
        ArrayList<Integer> lower = new ArrayList<>(); //lower half
        ArrayList<Integer> higher = new ArrayList<>(); //higher half
        for (int i = 0; i < cardCount / 2; i++) {
            lower.add(hand[i]);
        }
        for (int i = cardCount / 2; i < hand.length; i++) {
            higher.add(hand[i]);
        }
        for (int i = 0; i < cardCount / 2; i++) {
            int oppoCard = oppoHand[i];
            if (oppoCard > higher.get(higher.size() - 1)) continue;
            int card = Collections.binarySearch(higher, oppoCard);
            if (card < 0) {
                card = (card + 1) * -1;
            }
            higher.remove(card);
            wins++;
        }
        for (int i = cardCount / 2; i < cardCount; i++) {
            int oppoCard = oppoHand[i];
            if (oppoCard < lower.get(0)) continue;
            int card  = Collections.binarySearch(lower, oppoCard);
            if (card < 0) {
                card = (card + 1) * -1;
            }
            lower.remove(card - 1);
            wins++;
        }
        out.println(wins);
        out.close();
    }
}
