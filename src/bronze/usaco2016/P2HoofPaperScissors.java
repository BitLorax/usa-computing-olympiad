package bronze.usaco2016;

import java.util.*;
import java.io.*;

public class P2HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/hps.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/hps.out")));

        int rounds = Integer.parseInt(in.readLine());
        int[] results = new int[rounds];

        for (int round = 0; round < rounds; round++) {
            StringTokenizer st = new StringTokenizer(in.readLine());

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

        out.println(Math.max(winsI, winsII));
        out.close();
    }

}
