package day2_SearchingAndSorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Q6_MooSick {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int songLen = Integer.parseInt(in.nextLine());
        int[] song = new int[songLen];
        for (int i = 0; i < songLen; i++) {
            song[i] = Integer.parseInt(in.nextLine());
        }
        int chordLen = Integer.parseInt(in.nextLine());
        int[] chord = new int[chordLen];
        for (int i = 0; i < chordLen; i++) {
            chord[i] = Integer.parseInt(in.nextLine());
        }
        int detected = 0;
        int[] testPart = new int[chordLen];
        ArrayList<Integer> detectedIndices = new ArrayList<>();
        for (int i = 0; i <= song.length - chordLen; i++) {
            System.arraycopy(song, i, testPart, 0, chordLen);
            if (checkMatch(chord, testPart)) {
                detectedIndices.add(i + 1);
                detected++;
            }
        }
        System.out.println(detected);
        for (int i = 0; i < detectedIndices.size(); i++) {
            System.out.println(detectedIndices.get(i));
        }
    }
    private static boolean checkMatch(int[] chord, int[] pattern) {
        Arrays.sort(chord);
        Arrays.sort(pattern);
        int offset = chord[0] - pattern[0];
        for (int i = 1; i < chord.length; i++) {
            if (chord[i] - offset != pattern[i]) {
                return false;
            }
        }
        return true;
    }
}

