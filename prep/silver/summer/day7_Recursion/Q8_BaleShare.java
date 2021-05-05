package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q8_BaleShare {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int baleCount = Integer.parseInt(in.readLine());
        int[] bales = new int[baleCount];
        for (int i = 0; i < baleCount; i++) {
            bales[i] = Integer.parseInt(in.readLine());
        }
    }
}
