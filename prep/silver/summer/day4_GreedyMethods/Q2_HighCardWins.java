package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Q2_HighCardWins {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cardCount = Integer.parseInt(in.readLine());
        ArrayList<Integer> myCards = new ArrayList<>();
        int[] otherCards = new int[cardCount];
        for (int i = 0; i < cardCount; i++) {
            otherCards[i] = Integer.parseInt(in.readLine());;
        }
        Arrays.sort(otherCards);
        int index = 0;
        for (int i = 1; i <= cardCount * 2; i++) {
            if (Arrays.binarySearch(otherCards, i) < 0) {
                myCards.add(i);
                index++;
            }
        }
        Collections.sort(myCards);
        int wins = 0;
        int prevIndex = 0;
        for (int i = 0; i < cardCount; i++) {
            int opponent = otherCards[i];
            int chosenCard = Collections.binarySearch(myCards, opponent);
            if (chosenCard < 0) {
                chosenCard = (chosenCard + 1) * -1;
            } else {
                chosenCard++;
            }
            if (chosenCard < myCards.size()) {
                myCards.remove(chosenCard);
                wins++;
            }
        }
        System.out.println(wins);
    }
}
