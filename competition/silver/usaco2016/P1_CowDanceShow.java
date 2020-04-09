package silver.usaco2016;

import java.util.*;
import java.io.*;

public class P1_CowDanceShow {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/cowdance.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/cowdance.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int cowCount = Integer.parseInt(st.nextToken());
        int time = Integer.parseInt(st.nextToken());

        int[] times = new int[cowCount];
        for (int cow = 0; cow < cowCount; cow++) {
            times[cow] = Integer.parseInt(in.readLine());
        }

        int replaceInTime = 0;
        int currIndex = 0;
        for (int cow = currIndex; cow < cowCount; cow++) {
            if (times[cow] != -1) {
                int timeLeft = time - times[cow];
                times[cow] = -1;
                replaceInTime += calcReplace(times, timeLeft);
            }
            currIndex++;
        }

        out.println(replaceInTime);
        out.close();
    }

    private static int calcReplace(int[] times, int timeLeft) {
        int replaceInTime = 1;
        if (timeLeft != 0) {
            for (int cow = 0; cow < times.length; cow++) {
                if (times[cow] <= timeLeft && times[cow] != -1) {
                    timeLeft -= times[cow];
                    times[cow] = -1;
                    calcReplace(times, timeLeft);
                }
            }
        }
        return replaceInTime;
    }
}
