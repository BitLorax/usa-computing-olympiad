package silver.usaco2016;

import java.util.*;
import java.io.*;

public class P2CitiesAndStates {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/silver/resources/citystate.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources/citystate.out")));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int cityCount = Integer.parseInt(st.nextToken());

        Map<String, Integer> pairs = new HashMap<>();

        for (int pair = 0; pair < cityCount; pair++) {
            st = new StringTokenizer(br.readLine());

            String pairKey = st.nextToken().substring(0, 2) + st.nextToken();

            if (pairs.containsKey(pairKey)) {
                pairs.put(pairKey, pairs.get(pairKey) + 1);
            } else {
                pairs.put(pairKey, 1);
            }
        }

        int pairCount = 0;

        for (String pair : pairs.keySet()) {
            String pairKey = pair.substring(2, 4) + pair.substring(0, 2); // What the other city would look like
            if (pairs.containsKey(pairKey)) {
                pairCount += pairs.get(pairKey);
            }
        }

        pw.println(pairCount / 2); // Double counted
        pw.close();
    }
}
