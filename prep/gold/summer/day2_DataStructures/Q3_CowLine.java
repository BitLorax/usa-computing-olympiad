package day2_DataStructures;

import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Q3_CowLine {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Deque<Integer> line = new LinkedList<>();
        int changeCount = Integer.parseInt(in.readLine());
        int cowNum = 0;
        for (int i = 0; i < changeCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            char changeType = st.nextToken().charAt(0);
            char side = st.nextToken().charAt(0);
            if (changeType == 'A') {
                if (side == 'L') {
                    line.addFirst(cowNum);
                } else {
                    line.addLast(cowNum);
                }
                cowNum++;
            } else {
                int mag = Integer.parseInt(st.nextToken());
                for (int j = 0; j < mag; j++) {
                    if (side == 'L') {
                        line.removeFirst();
                    } else {
                        line.removeLast();
                    }
                }
            }
        }
        for (int i : line) {
            System.out.println(i + 1);
        }
    }
}
