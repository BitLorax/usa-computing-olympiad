package bronze.usaco2016;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class P3WhyDidTheCowCrossTheRoadIII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/cowqueue.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/cowqueue.out")));

        int queryCount = Integer.parseInt(in.readLine());
        Map<Integer, Integer> query = new TreeMap<>();
        for (int i = 0; i < queryCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            query.put(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        int time = 0;
        for (int cowTime : query.keySet()) {
            if (cowTime > time) {
                time = cowTime;
            }
            time += query.get(cowTime);
        }

        out.println(time);
        out.close();
    }
}
