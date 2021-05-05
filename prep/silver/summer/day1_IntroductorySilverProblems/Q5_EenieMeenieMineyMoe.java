package day1_IntroductorySilverProblems;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q5_EenieMeenieMineyMoe {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());

        int heiferCount = Integer.parseInt(st.nextToken());
        ArrayList<Integer> heifers = new ArrayList<>();
        for (int i = 0; i < heiferCount; i++) {
            heifers.add(i + 1);
        }
        int sequenceLen = Integer.parseInt(st.nextToken());
        int[] sequence = new int[sequenceLen];

        st = new StringTokenizer(in.nextLine());

        for (int i = 0; i < sequenceLen; i++) {
            sequence[i] = Integer.parseInt(st.nextToken());
        }

        int sequenceStep = 0;
        int currIndex = 0;
        while (heifers.size() != 1) {
            currIndex = (currIndex + sequence[sequenceStep] - 1) % heifers.size();
            heifers.remove(currIndex);

            sequenceStep = (sequenceStep + 1) % sequenceLen;
        }

        System.out.println(heifers.get(0));
    }
}
