package day4_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q8_Blink {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int bulbCount = Integer.parseInt(st.nextToken());
        long timePlayed = Long.parseLong(st.nextToken());
        boolean[] visited = new boolean[1 << bulbCount];
        String bulbString = "";
        for (int i = 0; i < bulbCount; i++) {
            bulbString += in.readLine();
        }
        int bulbs = Integer.parseInt(bulbString, 2);
        long time = -1;
        String newBulbString = bulbString;
        ArrayList<Integer> order = new ArrayList<>();
        while (!visited[bulbs] && time < timePlayed) {
            visited[bulbs] = true;
            time++;
            order.add(bulbs);
            bulbString = newBulbString;
            newBulbString = "";
            for (int i = 0; i < bulbCount; i++) {
                int j = i - 1;
                if (j < 0) j += bulbCount;
                char bulb = bulbString.charAt(i);
                if (bulbString.charAt(j) == '1') newBulbString += Math.abs(Character.getNumericValue(bulb) - 1);
                else newBulbString += bulb;
            }
            bulbs = Integer.parseInt(newBulbString, 2);
            if (bulbs == 0) {
                time = timePlayed;
                bulbString = newBulbString;
                break;
            }
        }
        int t = order.indexOf(1699);
        if (time != timePlayed) {
            int j = (int)(timePlayed % (order.size() - order.indexOf(bulbs)));
            if (j < 0) j += order.size();
            String temp = Integer.toBinaryString(order.get(j));
            bulbString = "";
            for (int i = 0; i < bulbCount - temp.length(); i++) bulbString += "0";
            for (int i = 0; i < temp.length(); i++) bulbString += temp.charAt(i);
        }
        for (int i = 0; i < bulbCount; i++) System.out.println(bulbString.charAt(i));
    }
}
