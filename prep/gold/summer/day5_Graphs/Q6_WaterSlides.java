package day5_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q6_WaterSlides {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int platformCount = Integer.parseInt(st.nextToken());
        int slideCount = Integer.parseInt(st.nextToken());
        ArrayList<Integer> inSlide = new ArrayList<>();
        ArrayList<Integer> outSlide = new ArrayList<>();
        int[] platformPositions = new int[platformCount];
        for (int i = 0; i < platformCount; i++) {
            platformPositions[i] = Integer.parseInt(in.readLine());
        }
        for (int i = 0; i < slideCount; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken()) - 1;
            int end = Integer.parseInt(st.nextToken()) - 1;
            int j = inSlide.indexOf(platformPositions[end]);
            if (j >= 0) inSlide.remove(j);
            else outSlide.add(platformPositions[end]);
            j = outSlide.indexOf(platformPositions[start]);
            if (j >= 0) outSlide.remove(j);
            else inSlide.add(platformPositions[start]);
        }
        Collections.sort(inSlide);
        Collections.sort(outSlide);
        int sum = 0;
        for (int i = 0; i < inSlide.size(); i++) {
            sum += Math.abs(inSlide.get(i) - outSlide.get(i));
        }
        System.out.println(sum);
    }
}
