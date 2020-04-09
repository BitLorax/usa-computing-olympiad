package silver.usaco2015;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class P2_HighCardWins {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2015/highcard.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2015/highcard.out")));
        int cardCount = Integer.parseInt(in.readLine());
        ArrayList<Integer> oppohand = new ArrayList<>();
        for (int i = 0; i < cardCount; i++) {
            oppohand.add(Integer.parseInt(in.readLine()));
        }
        Collections.sort(oppohand);
        ArrayList<Integer> hand = new ArrayList<>();
        for (int i = 1; i <= cardCount * 2; i++) {
            if (Collections.binarySearch(oppohand, i) < 0) {
                hand.add(i);
            }
        }
        Collections.sort(hand);

        int wins = 0;

        for (int i = 0; i < cardCount; i++) {
            int oppoCard = oppohand.get(i);
            if (oppoCard > hand.get(hand.size() - 1)) { //impossible to win, sacrifice lowest card
                hand.remove(0);
            } else {
                int index = Collections.binarySearch(hand, oppoCard);
                if (index < 0) {
                    index = (index + 1) * -1;
                }
                hand.remove(index);
                wins++;
            }
        }
        out.println(wins);
        out.close();
    }
}
