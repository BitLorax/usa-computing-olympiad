package day10_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q2_Moocast {
    private static int maxCows = 0;
    private static int cowsTransmitted = 1;
    private static boolean[] transmitted;
    private static Coord[] coords;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int coordCount = Integer.parseInt(in.readLine());
        coords = new Coord[coordCount];
        transmitted = new boolean[coordCount];
        for (int i = 0; i < coordCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            coords[i] = new Coord(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));
        }
        for (int i = 0; i < coordCount; i++) {
            transmitted = new boolean[coordCount];
            transmitted[i] = true;
            cowsTransmitted = 1;
            transmit(i);
        }
        System.out.println(maxCows);
    }
    private static void transmit(int currCow) {
        for (int i = 0; i < coords.length; i++) {
            if (i != currCow && coords[currCow].canTransmit(coords[i]) && !transmitted[i]) {
                transmitted[i] = true;
                cowsTransmitted++;
                maxCows = Math.max(cowsTransmitted, maxCows);
                transmit(i);
            }
        }
    }
    static class Coord {
        long x;
        long y;
        long power;
        Coord(long x, long y, long power) {
            this.x = x;
            this.y = y;
            this.power = power;
        }
        double getDist(Coord a) {
            double result = Math.sqrt(Math.abs((this.x - a.x) * (this.x - a.x)) + Math.abs((this.y - a.y) * (this.y - a.y)));
            return result;
        }
        boolean canTransmit(Coord a) {
            return getDist(a) <= power;
        }
    }
}
