package day1_IntroductorySilverProblems;

import java.util.Scanner;

public class Q3_BarnEchoes {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str1 = in.nextLine();
        String str2 = in.nextLine();

        int len = 0;
        for (int i = 1; i < Math.min(str1.length(), str2.length()); i++) {
            if (str1.substring(0, i).equals(str2.substring(str2.length() - i, str2.length()))) {
                len = i;
            }
        }
        for (int i = 1; i < Math.min(str1.length(), str2.length()); i++) {
            if (str2.substring(0, i).equals(str1.substring(str1.length() - i, str1.length()))) {
                len = Math.max(len, i);
            }
        }
        System.out.println(len);
    }
}
