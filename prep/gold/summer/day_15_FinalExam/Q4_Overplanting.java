package day_15_Final;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q4_Overplanting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int rectangleCount = Integer.parseInt(in.readLine());
        Side[] sides = new Side[2 * rectangleCount];
        for (int i = 0; i < rectangleCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            sides[i * 2] = new Side(x1, y1, y2);
            sides[i * 2 + 1] = new Side(x2, y1, y2);
        }
        Arrays.sort(sides);

    }
    static class Side implements Comparable<Side> {
        int x;
        int top;
        int bottom;
        Side(int x, int t, int b) {
            this.x = x;
            top = t;
            bottom = b;
        }
        public int compareTo(Side a) {
            return this.x - a.x;
        }
    }
}
