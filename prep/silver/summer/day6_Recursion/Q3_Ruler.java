package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q3_Ruler {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String ruler = "" + n;
        ruler += buildRuler(ruler, n - 1);
        ruler += n;
        for (int i = 0; i < ruler.length(); i++) {
            for (int j = 0; j < Integer.parseInt(ruler.substring(i, i + 1)); j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    private static String buildRuler(String ruler, int n) {
        if (n == 1) {
            return "1";
        }
        String firstHalf = buildRuler(ruler, n - 1);
        String secondHalf = buildRuler(ruler, n - 1);
        ruler = firstHalf + n + secondHalf;
        return ruler;
    }
}
