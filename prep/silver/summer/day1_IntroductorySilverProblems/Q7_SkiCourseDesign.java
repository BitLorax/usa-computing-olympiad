package day1_IntroductorySilverProblems;

import java.util.Arrays;
import java.util.Scanner;

public class Q7_SkiCourseDesign {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int hillCount = Integer.parseInt(in.nextLine());
        int[] hills = new int[hillCount];
        for (int i = 0; i < hillCount; i++) {
            int j = Integer.parseInt(in.nextLine());
            hills[i] = j;
        }
        Arrays.sort(hills);
        int total = 0;
        int minTotal = hills.length * (hills[hills.length - 1] * hills[hills.length - 1]);
        for (int i = hills[0]; i <= hills[hills.length - 1] - 17; i++) {
            int min = i;
            int max = min + 17;
            for (int j = 0; j < hills.length; j++) {
                if (hills[j] < min) {
                    total += (min - hills[j]) * (min - hills[j]);
                } else if (hills[j] > max) {
                    total += (hills[j] - max) * (hills[j] - max);
                }
            }
            minTotal = Math.min(minTotal, total);
            total = 0;
        }
        /*
        int over = 1;
        while (over != 0) {
            Arrays.sort(hills);
            over = (hills[hills.length - 1] - hills[0]) - 17;
            int mid = over / 2;
            hills[hills.length - 1] -= mid;
            hills[0] += (over - mid);
            total += (mid * mid) + ((over - mid) * (over - mid));
        }
        */
        System.out.println(minTotal);

    }
}
