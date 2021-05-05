package day4_Graphs;

import java.io.*;
import java.util.StringTokenizer;

public class Q1_DaisyChainsInTheField {
    private static boolean[][] connected;
    private static boolean[] cows;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int connectionCount = Integer.parseInt(st.nextToken());

        connected = new boolean[cowCount][cowCount];
        for (int i = 0; i < connectionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            connected[j][k] = true;
            connected[k][j] = true;
        }

        cows = new boolean[cowCount];
        getConnected(0);
        boolean connected = false;
        for (int i = 0; i < cowCount; i++) {
            if (!cows[i]) {
                System.out.println(i + 1);
                connected = true;
            }
        }
        if (!connected) System.out.println("0");
    }
    private static void getConnected(int currCow) {
        cows[currCow] = true;
        for (int i = 0; i < connected.length; i++) {
            if (connected[currCow][i] && !cows[i]) getConnected(i);
        }
    }
}
