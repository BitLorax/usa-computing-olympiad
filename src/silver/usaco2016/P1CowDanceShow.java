package silver.usaco2016;

/*

[Explanation]
Check if the cow times can be added up to be less than the time requirement, and replace the times in the list with -1 so it can't be used anymore.

 */

import java.util.*;
import java.io.*;

public class P1CowDanceShow {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/silver/resources/cowdance.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources/cowdance.out")));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int cowCount = Integer.parseInt(st.nextToken());
        int time = Integer.parseInt(st.nextToken());

        int[] times = new int[cowCount];
        for (int cow = 0; cow < cowCount; cow++) {
            times[cow] = Integer.parseInt(br.readLine());
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

        pw.println(replaceInTime);
        pw.close();
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
