package day13_ComputationalGeometry;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Q1_BovineBridgeBattle {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Coord[] cows = new Coord[cowCount];
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            cows[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Map<Integer, Integer> midpts = new TreeMap<>(); //hashed coordinates, quantity
        for (int i = 0; i < cowCount; i++) {
            for (int j = i + 1; j < cowCount; j++) {
                Coord midpt = new Coord(cows[i].x + cows[j].x, cows[i].y + cows[j].y);
                int hashed = midpt.hash();
                if (midpts.containsKey(hashed)) {
                    midpts.put(hashed, midpts.get(hashed) + 1);
                } else {
                    midpts.put(hashed, 1);
                }
            }
        }
        int pairs = 0;
        for (int midptCount : midpts.values()) {
            pairs += (midptCount * (midptCount - 1)) / 2;
        }
        System.out.println(pairs);
    }
    static class Coord {
        int x;
        int y;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
        int hash() { return this.x * 1000000000 + this.y; }
    }
}
