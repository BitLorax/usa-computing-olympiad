package bronze.usaco2016;

import java.util.*;
import java.io.*;

public class P1DontBeLast {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/notlast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/notlast.out")));

        int cowRecordCount = Integer.parseInt(in.readLine());
        Map<String, Integer> record = new HashMap<>();

        for (int cow = 0; cow < cowRecordCount; cow++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            String name = st.nextToken();
            if (!record.containsKey(name)) {
                record.put(name, Integer.parseInt(st.nextToken()));
            } else {
                record.put(name, record.get(name) + Integer.parseInt(st.nextToken()));
            }
        }
        int smallest = 101;
        for (String name : record.keySet()) {
            if (record.get(name) < smallest) {
                smallest = record.get(name);
            }
        }
        int secondSmallest = 101;
        for (String name : record.keySet()) {
            if (record.get(name) > smallest && record.get(name) < secondSmallest) {
                secondSmallest = record.get(name);
            }
        }

        out.println(getKeyFromValue(record, secondSmallest));
        out.close();
    }

    private static String getKeyFromValue(Map<String, Integer> record, int value) {
        String correctName = "NULL";
        for (String name : record.keySet()) {
            if (record.get(name) == value) {
                correctName = name;
            }
        }
        return correctName;
    }
}
