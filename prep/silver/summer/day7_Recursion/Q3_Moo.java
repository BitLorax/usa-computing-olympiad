package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q3_Moo {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int letter = Integer.parseInt(in.readLine());
        int[] i = getLen(0, letter, 0);
        while (true) {
            if (i[0] == 3) {
                if (letter == 1) {
                    System.out.println("m");
                    break;
                } else {
                    System.out.println("o");
                    break;
                }
            }
            int midLen = i[1] + 3;
            int midStart = (i[0] - midLen) / 2 + 1;
            if (letter >= midStart && letter < midStart + midLen) {
                if (letter == midStart) {
                    System.out.println("m");
                    break;
                } else {
                    System.out.println("o");
                    break;
                }
            } else {
                if (letter > midStart) {
                    letter -= midLen;
                    letter -= (i[0] - midLen) / 2;
                }
                i = getLen(0, letter, 0);
            }
        }
    }
    private static int[] getLen(int currLen, int letter, int n) {
        int test = currLen * 2 + (n + 3);
        if (test > letter) {
            int[] i = {currLen * 2 + (n + 3), n};
            return i;
        } else {
            return getLen(test, letter, ++n);
        }
    }
    /*
    private static String constructMoo(int letter, String moo, int oLen) {
        String newMoo = moo;
        if (moo.length() < letter) {
            newMoo += "m";
            for (int i = 0; i < oLen; i++) {
                newMoo += "o";
            }
            newMoo += moo;
            newMoo = constructMoo(letter, newMoo, ++oLen);
        }
        return newMoo;
    }
    private static String findMoo(int letter, int oLen, int index, String pattern) {
        String temp = pattern;
        pattern = "" + oLen;
        if (temp.length() > 1) {
            pattern += temp.substring(1, temp.length());
            pattern += temp.substring(0, 1);
            pattern += temp.substring(1, temp.length());
        } else {
            pattern += temp;
        }

        for (int i = 0; i < pattern.length(); i++) {
            int currOLen = Integer.parseInt(pattern.substring(i, i + 1));
            index++;
            if (index == letter) {
                return "m";
            }
            for (int j = 0; j < currOLen; j++) {
                index++;
                if (index == letter) {
                    return "o";
                }
            }
        }
        return findMoo(letter, ++oLen, index, pattern);
    }
    private static String getOLen(int n) {
        if (n == 0) {
            return "2";
        } else {
            String mooBefore = getOLen(n - 1);
            String moo = mooBefore;
            moo += (n + 2);
            moo += mooBefore;

            return moo;
        }
    }
    */
}
