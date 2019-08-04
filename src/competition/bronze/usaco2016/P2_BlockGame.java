package bronze.usaco2016;

import java.util.*;
import java.io.*;

public class P2_BlockGame {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/blocks.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/blocks.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int boards = Integer.parseInt(st.nextToken());
        int[] allLetters = new int[26];

        for (int board = 0; board < boards; board++) {

            st = new StringTokenizer(in.readLine());
            String side1 = st.nextToken();
            int[] letters1 = blocksRequired(side1);
            String side2 = st.nextToken();
            int[] letters2 = blocksRequired(side2);

            for (int letter = 0; letter < 26; letter++) {
                allLetters[letter] += Math.max(letters1[letter], letters2[letter]);
            }
        }

        for (int letter = 0; letter < 26; letter++) {
            out.println(allLetters[letter]);
        }
        out.close();

    }

    private static int[] blocksRequired (String word) {
        int[] letters = new int[26];
        for (int letter = 0; letter < word.length(); letter++) {
            int requiredLetter = word.charAt(letter) - 'a' + 1;
            letters[requiredLetter - 1] += 1;
        }
        return letters;
    }
}
