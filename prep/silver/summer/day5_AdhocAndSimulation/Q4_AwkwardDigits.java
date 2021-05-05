package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q4_AwkwardDigits {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String binaryIn = in.readLine();
        String base3 = in.readLine();
        int[] binary = new int[binaryIn.length()];
        for (int i = 0; i < binaryIn.length(); i++) {
            binary[i] = Integer.parseInt(binaryIn.substring(i, i + 1));
        }
        int[] decimalPossibilities = new int[binary.length];
        String[] base3Possibilities = new String[binary.length];
        for (int i = 0; i < binaryIn.length(); i++) {
            int[] copy = binary.clone();
            copy[i] = Math.abs(binary[i] - 1);
            decimalPossibilities[i] = Integer.parseInt(toString(copy), 2);
            base3Possibilities[i] = toBase3(Integer.parseInt(toString(copy), 2));
        }

        for (int i = 0; i < base3Possibilities.length; i++) {
            String match = "";
            if (base3.length() == base3Possibilities[i].length()) {
                int diff = 0;
                for (int j = 0; j < base3.length(); j++) {
                    if (base3.charAt(j) != base3Possibilities[i].charAt(j)) {
                        diff++;
                    }
                    if (diff > 1) {
                        break;
                    }
                    if (j == base3.length() - 1 && diff == 1) {
                        match = base3Possibilities[i];
                        break;
                    }
                }
                if (diff == 1) {
                    System.out.println(Integer.parseInt(match, 3));
                    break;
                }
            }
        }

    }
    private static String toString(int[] lst) {
        String result = "";
        for (int i = 0; i < lst.length; i++) {
            result += lst[i];
        }
        return result;
    }
    private static String toBase3(int num) {
        String result = "";
        while (true) {
            if (num / 3 == 0) {
                break;
            }
            result += num % 3;
            num /= 3;
        }
        result += num;
        return new StringBuilder(result).reverse().toString();
    }
}
