package bronze.usaco2016;

/*

[Explanation]
Put the information into a Map and apply the changes.
At the end, find the smallest milkValue and then the second smallest and use it to find the name of the cow.

 */

import java.util.*;
import java.io.*;

public class P1DontBeLast {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/bronze/resources/notlast.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources/notlast.out")));

        int cowRecordCount = Integer.parseInt(br.readLine());
        Map<String, Integer> record = new HashMap<>();

        for (int cow = 0; cow < cowRecordCount; cow++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
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

        pw.println(getKeyFromValue(record, secondSmallest));
        pw.close();
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
