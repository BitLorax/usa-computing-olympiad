package gold.usaco2015;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class P2_FruitFeast {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/gold/resources2015/feast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gold/resources2015/feast.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int maxFull = Integer.parseInt(st.nextToken());
        int orange = Integer.parseInt(st.nextToken());
        int lemon = Integer.parseInt(st.nextToken());
        boolean[][] found = new boolean[2][maxFull + 1];
        found[0][0] = true;
        int max = 0;
        for (int i = 0; i < found.length; i++) {
            for (int j = 0; j < found[0].length; j++) {
                if (!found[i][j]) continue;
                if (j + orange <= maxFull) {
                    found[i][j + orange] = true;
                    max = Math.max(max, j + orange);
                }
                if (j + lemon <= maxFull) {
                    found[i][j + lemon] = true;
                    max = Math.max(max, j + lemon);
                }
                if (i + 1 < 2) found[i + 1][j / 2] = true;
            }
        }

        out.println(max);
        out.close();
    }

}
