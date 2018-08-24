package silver.usaco2016;

import java.util.*;
import java.io.*;

public class P1_CountingHaybales {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/haybales.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/haybales.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int haybales = Integer.parseInt(st.nextToken());
        int queries = Integer.parseInt(st.nextToken());
        int[] locations = new int[haybales];

        st = new StringTokenizer(in.readLine());
        for (int haybale = 0; haybale < haybales; haybale++) {
            locations[haybale] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(locations);

        for (int query = 0; query < queries; query++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            out.println(findHaybales(locations, b) - findHaybales(locations, a - 1));
        }

        out.close();
    }

    // Binary search for interval
    private static int findHaybales(int[] locations, int limit) {
        if (locations[0] > limit) {
            return 0;
        } else {
           int min = 0;
           int max = locations.length - 1;
           int mid;
           while (min != max) {
               mid = (min + max + 1) / 2;
               if (limit >= locations[mid]) {
                   min = mid;
               } else {
                   max = mid - 1;
               }
           }
           return min + 1;
        }
    }
}
