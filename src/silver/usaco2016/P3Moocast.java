package silver.usaco2016;

import java.io.*;
import java.util.*;

public class P3Moocast {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/silver/resources/moocast.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources/moocast.out")));

        int cowCount = Integer.parseInt(br.readLine());
        int[] x = new int[cowCount];
        int[] y = new int[cowCount];
        int[] p = new int[cowCount];

        for (int row = 0; row < cowCount; row++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[row] = Integer.parseInt(st.nextToken());
            y[row] = Integer.parseInt(st.nextToken());
            p[row] = Integer.parseInt(st.nextToken());
        }

        boolean[][] canConnect = new boolean[cowCount][cowCount];
        for (int cow = 0; cow < cowCount; cow++) {
            for (int connectAttempt = 0; connectAttempt < cowCount; connectAttempt++) {
                int connectDistanceSquared = (x[cow] - x[connectAttempt]) * (x[cow] - x[connectAttempt]) + (y[cow] - y[connectAttempt]) * (y[cow] - y[connectAttempt]);
                if (connectDistanceSquared < (p[cow] * p[cow])) {
                    canConnect[cow][connectAttempt] = true;
                }
            }
        }
        int connected = 0;
        for (int cow = 0; cow < cowCount; cow++) {
            connected = Math.max(connected, totalConnected(canConnect, cow));
        }
        pw.println(connected);
        pw.close();
    }

    private static int totalConnected(boolean[][] canConnect, int cow) {
        int connected = 1;
        for (int connectAttempt = 0; connectAttempt < canConnect[cow].length; connectAttempt++) {
            if (canConnect[cow][connectAttempt] && connectAttempt != cow) {
                connected += totalConnected(canConnect, connectAttempt);
            }

        }
        return connected;
    }
}

