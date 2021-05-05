package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//sweepline?

public class Q4_PaintingTheFence {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int moveCount = Integer.parseInt(in.readLine());
        ChangePoint[] changes = new ChangePoint[moveCount * 2];
        int currPos = 0;
        for (int i = 0; i < moveCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int mag = Integer.parseInt(st.nextToken());
            String direc = st.nextToken();
            if (direc.equals("R")) {
                changes[i * 2] = new ChangePoint(1, currPos);
                currPos += mag;
                changes[i * 2 + 1] = new ChangePoint(-1, currPos);
            } else {
                changes[i * 2] = new ChangePoint(-1, currPos);
                currPos -= mag;
                changes[i * 2 + 1] = new ChangePoint(1, currPos);
            }
        }
        Arrays.sort(changes);
        int currSum = 0;
        int painted = 0;
        for (int i = 0; i < changes.length; i++) {
            int netChange = changes[i].change;
            int k = 0;
            for (int j = i + 1; j < changes.length; j++) {
                if (changes[j].pos == changes[i].pos) {
                    netChange += changes[j].change;
                    k++;
                } else {
                    break;
                }
            }
            int intervalLen;
            if (i > 0) {
                intervalLen = changes[i].pos - changes[i - 1].pos;
            } else {
                intervalLen = 0;
            }
            if (currSum >= 2) {
                painted += intervalLen;
            }
            currSum += netChange;
            i += k;
        }
        System.out.println(painted);

    }
    static class ChangePoint implements Comparable<ChangePoint> {
        int change;
        int pos;
        ChangePoint(int change, int pos) {
            this.change = change;
            this.pos = pos;
        }
        public int compareTo(ChangePoint a) {
            return this.pos - a.pos;
        }
    }
}
