package day6_DynamicProgramming;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q6_WaterSlides {
    private static ArrayList<Integer>[] to;
    private static ArrayList<Integer>[] values;
    private static long[][] visited; //node by visited
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int vertexCount = Integer.parseInt(st.nextToken());
        int edgeCount = Integer.parseInt(st.nextToken());
        int mistakeLimit = Integer.parseInt(st.nextToken());
        to = new ArrayList[vertexCount];
        values = new ArrayList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            to[i] = new ArrayList<>();
            values[i] = new ArrayList<>();
        }
        for (int i = 0; i < edgeCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            to[j].add(k);
            values[j].add(l);
        }
        visited = new long[vertexCount][mistakeLimit + 1];
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j <= mistakeLimit; j++) visited[i][j] = 1000000000;
        }
        System.out.println(rideSlide(0, mistakeLimit));
    }
    private static long rideSlide(int node, int mistakesLeft) { //top loop is guarantee of control currNode, bottom loop finds guarantee of lose control, then finds minimum of both guarantees
        if (visited[node][mistakesLeft] != 1000000000) return visited[node][mistakesLeft];
        long controlledAns = 0;
        for (int i = 0; i < to[node].size(); i++) {
            long dist = values[node].get(i);
            dist += rideSlide(to[node].get(i), mistakesLeft);
            controlledAns = Math.max(controlledAns, dist); //because controlled, choose best path
        }
        long uncontrolledAns = Integer.MAX_VALUE;
        if (mistakesLeft > 0) {
            for (int i = 0; i < to[node].size(); i++) {
                long dist = values[node].get(i);
                dist += rideSlide(to[node].get(i), mistakesLeft - 1);
                uncontrolledAns = Math.min(uncontrolledAns, dist); //not controlled, must take worst case
            }
        }
        long ans = Math.min(controlledAns, uncontrolledAns); //min to guarantee, controlled start may be less than uncontrolled start *
        visited[node][mistakesLeft] = ans;
        return ans;
    }
}
/*
example of controlled start < uncontrolled start
3 4 1
1 2 5
1 2 4
2 3 5
2 3 3

[1]___5___[2]___5___[3]
   \__4___/ \___3___/
controlled start at 1: 5 -> lose control at 2 -> 3 = 8
uncontrolled start at 1: lose control at 1 -> 4 -> 5 = 9
9 > 8
 */
