package day7_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q6_ForgottenPassword {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int passwordLen = Integer.parseInt(st.nextToken());
        int dictLen = Integer.parseInt(st.nextToken());
        String remembered = in.readLine();
        String[] dictionary = new String[dictLen];
        for (int i = 0; i < dictLen; i++) dictionary[i] = in.readLine();
        Arrays.sort(dictionary);
        String[] states = new String[passwordLen + 1];
        states[0] = "";
        for (int i = 0; i <= passwordLen; i++) {
            for (int j = 0; j < dictLen; j++) {
                if (i - dictionary[j].length() < 0) continue;
                if (states[i - dictionary[j].length()] != null && fits(remembered.substring(i - dictionary[j].length(), i), dictionary[j])) {
                    if (states[i] == null || states[i].compareTo(states[i - dictionary[j].length()] + dictionary[j]) > 0) states[i] = states[i - dictionary[j].length()] + dictionary[j];
                }
            }
        }
        System.out.println(states[passwordLen]);
    }
    private static boolean fits(String compareTo, String compare) {
        for (int i = 0; i < compareTo.length(); i++) {
            if (compareTo.charAt(i) != '?' && compareTo.charAt(i) != compare.charAt(i)) return false;
        }
        return true;
    }
    static class Connection implements Comparable<Connection>{
        int cost;
        int position;
        Connection(int c, int p) {
            cost = c;
            position = p;
        }
        public int compareTo(Connection a) {
            return this.cost - a.cost;
        }
    }
}
