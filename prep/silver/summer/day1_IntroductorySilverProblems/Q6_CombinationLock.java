package day1_IntroductorySilverProblems;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Q6_CombinationLock {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int lockSize = Integer.parseInt(in.nextLine());
        int[][] locks = new int[2][3];
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(in.nextLine());
            for (int j = 0; j < 3; j++) {
                locks[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int working = 0;
        for (int i = 1; i <= lockSize; i++) {
            for (int j = 1; j <= lockSize; j++) {
                for (int k = 1; k <= lockSize; k++) {
                    int[] attempt = {i, j, k};
                    if (withinRange(locks[0], attempt, lockSize) || withinRange(locks[1], attempt, lockSize)) {
                        working++;
                    }
                }
            }
        }
        System.out.println(working);
    }
    private static int subtractWrap(int num1, int num2, int wrap) {
        int result = num1 - num2;
        while (result < 0) {
            result += wrap;
        }
        return result;
    }
    private static boolean withinRange(int[] lock, int[] attempt, int wrap) {
        for (int i = 0; i < 3; i++) {
            if (subtractWrap(lock[i], attempt[i], wrap) > 2 && subtractWrap(attempt[i], lock[i], wrap) > 2) {
                return false;
            }
        }
        return true;
    }
}
