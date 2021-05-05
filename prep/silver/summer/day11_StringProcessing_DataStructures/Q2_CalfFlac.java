package day11_StringProcessing_DataStructures;

import java.io.IOException;
import java.util.Scanner;

public class Q2_CalfFlac {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String test = "";
        String inStr;
        while (in.hasNextLine()) {
            test += in.nextLine() + "\n";
        }
        //String onlyLetters = "";
        String palindrome = "";
        /*
        for (int i = 0; i < test.length(); i++) {
            if (Character.isLetter(test.charAt(i))) {
                onlyLetters += Character.toLowerCase(test.charAt(i));
            }
        }
        */
        String ans = "";
        int lo;
        int hi;
        for (int i = 2; i < test.length() - 1; i++) {
            if (Character.isLetter(test.charAt(i))) {
                String curr = test.substring(i, i + 1);
                lo = getPreviousChar(test, i);
                hi = getNextChar(test, i);
                int j = getPreviousChar(test, i);
                if (j != -1) {
                    if (test.charAt(j) == test.charAt(i)) {
                        lo = getPreviousChar(test, lo);
                    }
                }
                String result = calcPalin(test, lo, hi, curr);
                if (ans.length() < result.length()) {
                    ans = result;
                }
            }
        }
        int len = 0;
        for (int i = 0; i < ans.length(); i++) {
            if (Character.isLetter(ans.charAt(i))) {
                len++;
            }
        }
        System.out.println(len);
        System.out.println(ans);
    }
    private static String calcPalin(String in, int lo, int hi, String curr) {
        if (lo < 0 || hi < 0) {
            return curr;
        } else {
            if (Character.toLowerCase(in.charAt(lo)) == Character.toLowerCase(in.charAt(hi))) {
                curr = in.substring(lo, hi + 1);
                lo = getPreviousChar(in, lo);
                hi = getNextChar(in, hi);
                return calcPalin(in, lo, hi, curr);
            } else {
                return curr;
            }
        }
    }
    private static int getPreviousChar(String in, int currIndex) {
        currIndex--;
        if (currIndex < 0) {
            return -1;
        }
        while (!Character.isLetter(in.charAt(currIndex))) {
            currIndex--;
            if (currIndex < 0) {
                return -1;
            }
        }
        return currIndex;
    }
    private static int getNextChar(String in, int currIndex) {
        currIndex++;
        if (currIndex >= in.length()) {
            return -1;
        }
        while (!Character.isLetter(in.charAt(currIndex))) {
            currIndex++;
            if (currIndex >= in.length()) {
                return -1;
            }
        }
        return currIndex;
    }
}
