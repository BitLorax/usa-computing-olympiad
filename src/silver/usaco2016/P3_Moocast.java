package silver.usaco2016;

import java.io.*;
import java.util.*;

public class P3_Moocast {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/moocast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/moocast.out")));

        int cowCount = Integer.parseInt(in.readLine());
        int[] x = new int[cowCount];
        int[] y = new int[cowCount];
        int[] p = new int[cowCount];

        for (int row = 0; row < cowCount; row++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
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
        out.println(connected);
        out.close();
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

