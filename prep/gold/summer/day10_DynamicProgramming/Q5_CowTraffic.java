package day10_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q5_CowTraffic {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int nodeCount = Integer.parseInt(st.nextToken());
        int connectionCount = Integer.parseInt(st.nextToken());
        boolean[][] connected = new boolean[nodeCount][nodeCount];
        boolean[] notStart = new boolean[nodeCount];
        boolean[] notEnd = new boolean[nodeCount];
        for (int i = 0; i < connectionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            connected[j][k] = true;
            notStart[k] = true;
            notEnd[j] = true;
        }
        int[] statesToNode = new int[nodeCount];
        for (int i = 0; i < nodeCount; i++) if (!notStart[i]) statesToNode[i] = 1;
        for (int i = 0; i < nodeCount; i++) {
            if (statesToNode[i] != 0) continue;
            int sum = 0;
            for (int j = 0; j < i; j++) {
                if (connected[j][i]) sum += statesToNode[j];
            }
            statesToNode[i] = sum;
        }
        boolean[][] connectedReversed = new boolean[nodeCount][nodeCount];
        for (int i = 0; i < nodeCount; i++) {
            for (int j = 0; j < nodeCount; j++) {
                if (connected[i][j]) {
                    connectedReversed[j][i] = true;
                }
            }
        }
        int[] statesToEnd = new int[nodeCount];
        for (int i = 0; i < nodeCount; i++) if (!notEnd[i]) statesToEnd[i] = 1;
        for (int i = nodeCount - 1; i >= 0; i--) {
            if (statesToEnd[i] != 0) continue;
            int sum = 0;
            for (int j = nodeCount - 1; j > i; j--) {
                if (connectedReversed[j][i]) sum += statesToEnd[j];
            }
            statesToEnd[i] = sum;
        }
        int max = 0;
        for (int i = 0; i < nodeCount; i++) {
            if (notEnd[i]) max = Math.max(max, statesToNode[i] * statesToEnd[i]);
        }
        System.out.println(max);
    }
}
