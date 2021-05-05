package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1_CowCotillion {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int queries = Integer.parseInt(in.readLine());
        for (int i = 0; i < queries; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int len = Integer.parseInt(st.nextToken());
            String pattern = st.nextToken();
            if (isLegal(pattern)) {
                System.out.println("legal");
            } else {
                System.out.println("illegal");
            }
        }
    }
    private static boolean isLegal(String pattern) {
        int sum = 0;
        for (int i = 0; i < pattern.length(); i++) {
            if (pattern.charAt(i) == '>') {
                sum++;
            } else if (pattern.charAt(i) == '<') {
                sum--;
            }
            if (sum < 0) {
                return false;
            }
        }
        if (sum == 0) {
            return true;
        }
        return false;
    }
}
