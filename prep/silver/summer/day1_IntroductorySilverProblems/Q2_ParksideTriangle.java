package day1_IntroductorySilverProblems;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Q2_ParksideTriangle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int SIZE = Integer.parseInt(st.nextToken());
        int seed = Integer.parseInt(st.nextToken());

        int diff;
        int start = seed;
        int size = SIZE;
        for (int i = 0; i < SIZE; i++) {
            for (int k = 0; k < i; k++) {
                System.out.print("  ");
            }
            if (i == 0) {
                diff = 0;
            } else {
                diff = i + 1;
            }
            start = addWrap(start, diff);
            int num = start;
            for (int j = 0; j < size; j++) {
                System.out.print(num);
                if (j != size - 1) {
                    System.out.print(" ");
                }
                num = addWrap(num, j + 1 + i);
            }
            size--;
            System.out.println();
        }
    }
    private static int addWrap(int num1, int num2) {
        if ((num1 + num2) % 9 == 0) {
            return 9;
        } else {
            return (num1 + num2) % 9;
        }
    }
}
