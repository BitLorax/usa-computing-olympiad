package silver.usaco2015;

import java.io.*;
import java.util.StringTokenizer;

public class P3_BreedCounting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2015/bcount.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2015/bcount.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int queryCount = Integer.parseInt(st.nextToken());
        int[][] cows = new int[cowCount][3]; //prefix sums
        for (int i = 0; i < cowCount; i++) {
            if (i != 0) {
                cows[i] = cows[i - 1].clone();
            }
            cows[i][Integer.parseInt(in.readLine()) - 1]++;
        }
        for (int i = 0; i < queryCount; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken()) - 2; //exclusive
            int end = Integer.parseInt(st.nextToken()) - 1; //inclusive
            for (int j = 0; j < 3; j++) {
                if (start >= 0) {
                    out.print(cows[end][j] - cows[start][j]);
                } else {
                    out.print(cows[end][j]);
                }
                if (j != 2) out.print(" ");
            }
            out.println();
            out.flush();
        }
    }
}
