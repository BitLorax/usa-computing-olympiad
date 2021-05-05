package day15_Final;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1_CowCounting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int avoidDig = Integer.parseInt(st.nextToken());

        int currNum = 0;
        while (cowCount > 0) {
            currNum++;
            double i = containsDigit(currNum, avoidDig);
            if (i >= 0) {
                currNum += Math.pow(10.0, i);
            }
            cowCount--;
        }
        System.out.println(currNum);
    }
    private static double containsDigit(int num, int targetDig) {
        String numStr = "" + num;
        String targetStr = "" + targetDig;
        char targetChar = targetStr.charAt(0);
        for (int i = numStr.length() - 1; i >= 0; i--) {
            if (numStr.charAt(i) == targetChar) {
                return (double)numStr.length() - i - 1;
            }
        }
        return -1.0;
    }
}
