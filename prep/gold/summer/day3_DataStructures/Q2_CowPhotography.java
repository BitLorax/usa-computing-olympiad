package day3_DataStructures;

import java.io.*;
import java.util.*;

public class Q2_CowPhotography {
    private static Integer[][] lines;
    private static Map<Integer, int[]> locations;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        lines = new Integer[5][cowCount];
        locations = new HashMap<>();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < cowCount; j++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int k = Integer.parseInt(st.nextToken());
                lines[i][j] = k;
                if (i == 0) locations.put(k, new int[5]);
                locations.get(k)[i] = j;
            }
        }
        Integer[] toBeCorrect = lines[0].clone();
        Arrays.sort(toBeCorrect, new Comp());
        for (int i : toBeCorrect) System.out.println(i);
    }
    static class Comp implements Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b) {
            int inOrder = 0; //how many times a is after b
            for (int i = 0; i < lines.length; i++) {
                int j = locations.get(a)[i];
                int k = locations.get(b)[i];
                if (j > k) {
                    inOrder++;
                }
            }
            if (inOrder >= lines.length - 2) return 1;
            return -1;
        }
    }
}
