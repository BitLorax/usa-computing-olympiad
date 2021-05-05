package day13_ComputationalGeometry;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q6_Bobsledding {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int courseLen = Integer.parseInt(st.nextToken());
        int turnCount = Integer.parseInt(st.nextToken());
        Turn[] turnInfo = new Turn[turnCount + 2];
        for (int i = 1; i <= turnCount; i++) {
            st = new StringTokenizer(in.readLine());
            turnInfo[i] = new Turn(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        turnInfo[0] = new Turn(0, 1);
        turnInfo[turnCount + 1] = new Turn(courseLen, 1000000001);
        Arrays.sort(turnInfo);
        int speed = 1;
        for (int i = 1; i < turnCount + 2; i++) {
            speed = Math.min(speed + turnInfo[i].pos - turnInfo[i - 1].pos, turnInfo[i].limit);
            turnInfo[i].limit = speed;
        }
        speed = 1000000001;
        for (int i = turnCount; i >= 0; i--) {
            speed = Math.min(speed + turnInfo[i + 1].pos - turnInfo[i].pos, turnInfo[i].limit);
            turnInfo[i].limit = speed;
        }
        int maxHeight = 0;
        for (int i = 1; i < turnCount + 2; i++) {
            int heightBefore = turnInfo[i - 1].limit;
            int heightCurr = turnInfo[i].limit;
            int dist = turnInfo[i].pos - turnInfo[i - 1].pos - 1;
            dist -= Math.abs(heightBefore - heightCurr);
            maxHeight = Math.max(maxHeight, (dist + 1) / 2 + Math.max(heightBefore, heightCurr));
        }
        System.out.println(maxHeight);
    }
    static class Turn implements Comparable<Turn> {
        int pos;
        int limit;
        Turn (int pos, int limit) {
            this.pos = pos;
            this.limit = limit;
        }
        public int compareTo(Turn a) {return this.pos - a.pos;}
    }
}
