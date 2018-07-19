package bronze.usaco2016;

import java.io.*;
import java.util.*;

public class P1WhyDidTheCowCrossTheRoadI {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/crossroad.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/crossroad.out")));

        int recordCount = Integer.parseInt(in.readLine());
        int[] seen = new int[11]; // 10 cows possible
        int crossings = 0;
        for (int record = 0; record < recordCount; record++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int cowID = Integer.parseInt(st.nextToken());
            if (seen[cowID] == 0) {
                seen[cowID] = Integer.parseInt(st.nextToken()) + 1; // bc 0 already represent not seen yet
            } else {
                if (Integer.parseInt(st.nextToken()) + 1 != seen[cowID]) {
                    crossings++;
                }
            }
        }

        out.println(crossings);
        out.close();
    }
}
