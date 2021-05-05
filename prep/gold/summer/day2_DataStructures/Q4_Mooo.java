package day2_DataStructures;

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q4_Mooo {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Sound[] cows = new Sound[cowCount];
        int[] volume = new int[cowCount];

        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            cows[i] = new Sound(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Stack<Integer> heights = new Stack<>();
        for (int i = cowCount - 1; i >= 0; i--) {
            while (!heights.isEmpty() && cows[i].height > cows[heights.peek()].height) {
                volume[i] += cows[heights.pop()].mag;
            }
            if (!heights.empty()) {
                volume[heights.peek()] += cows[i].mag;
            }
            heights.add(i);
        }
        int maxVol = 0;
        for (int i : volume) {
            maxVol = Math.max(maxVol, i);
        }
        System.out.println(maxVol);
    }
    static class Sound {
        int height;
        int mag;
        Sound (int h, int m) {
            this.height = h;
            this.mag = m;
        }
    }
}
