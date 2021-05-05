package day10_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q1_BreedProximity {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int crowdedDist = Integer.parseInt(st.nextToken());
        int[] positions = new int[1000001];
        for (int i = 0; i <= 1000000; i++) {
            positions[i] = -1;
        }
        int max = 0;
        for (int i = 0; i < cowCount; i++) {
            int cow = Integer.parseInt(in.readLine());
            if (positions[cow] != -1) if (Math.abs(positions[cow] - i) <= crowdedDist) max = Math.max(max, cow);
            positions[cow] = i;
        }
        System.out.println(max);
    }
}
