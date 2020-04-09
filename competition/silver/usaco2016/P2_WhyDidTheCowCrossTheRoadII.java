package silver.usaco2016;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P2_WhyDidTheCowCrossTheRoadII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/maxcross.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/maxcross.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int signals = Integer.parseInt(st.nextToken());
        int requirement = Integer.parseInt(st.nextToken());
        int brokenCount = Integer.parseInt(st.nextToken());

        int[] broken = new int[brokenCount];
        for (int i = 0; i < brokenCount; i++) {
            broken[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(broken);

        //Sliding window
        int[] lights = new int[signals];
        for (int i = 0; i < signals; i++) {
            if (Arrays.binarySearch(broken, i + 1) < 0) {
                lights[i] = 1;
            }
        }
        int sum = 0;
        int minFix = Integer.MAX_VALUE;
        for (int i = 0; i < requirement; i++) {
            sum += lights[i];
        }
        for (int i = 1; i <= signals - requirement; i++) {
            sum -= lights[i - 1];
            sum += lights[i + requirement - 1];
            minFix = Math.min(minFix, requirement - sum);
        }

        out.println(minFix);
        out.close();
    }
}
