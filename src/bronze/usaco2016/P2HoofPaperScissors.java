package bronze.usaco2016;

/*

[Explanation]
There are two possible patterns:
    I) 1 -> 2 -> 3 -> 1
    II) 1 -> 3 -> 2 -> 1

The win conditions are:
    I:              II:
    1 -> 2: +1      1 -> 3: +2
    2 -> 3: +1      3 -> 2: -1
    3 -> 1: -2      2 -> 1: -1

Shown in the data, the pattern that follows for a win condition is +/- 1 and the opposite sign for 2.

 */

import java.util.*;
import java.io.*;

public class P2HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/bronze/resources/hps.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources/hps.out")));

        int rounds = Integer.parseInt(br.readLine());
        int[] results = new int[rounds];

        for (int round = 0; round < rounds; round++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            results[round] = Integer.parseInt(st.nextToken()) - Integer.parseInt(st.nextToken());
        }

        // Examine both conditions
        // I
        int winsI = 0;
        for (int result : results) {
            if (result == 1 || result == -2) {
                winsI++;
            }
        }
        // II
        int winsII = 0;
        for (int result: results) {
            if (result == -1 || result == 2) {
                winsII++;
            }
        }

        pw.println(Math.max(winsI, winsII));
        pw.close();
    }

}
