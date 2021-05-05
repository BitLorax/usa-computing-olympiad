package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
HINTS:
3 vertical and 0 vertical is symmetrical, same with 1 and 2 vertical
brute force is 1 line through all x/y, then see if the remaining has only opposite
 */

public class Q7_ThreeLines {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Coord[] coords = new Coord[cowCount];
        Coord[] coordsFlipped = new Coord[cowCount];
        boolean[] covered;
        TreeSet<Integer> xCount = new TreeSet<>();
        TreeSet<Integer> yCount = new TreeSet<>();
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            coords[i] = new Coord(x, y);
            xCount.add(x);
            yCount.add(y);
        }
        if (xCount.size() > 3 && yCount.size() > 3) {
            Arrays.sort(coords);
            boolean success = true;
            int prevX = -1;
            for (int i = 0; i < coords.length; i++) { //for every x val
                Coord currCoord = coords[i];
                if (currCoord.x != prevX) { //if this x hasn't been tested yet
                    covered = new boolean[cowCount];
                    covered[i] = true;
                    for (int j = i + 1; j < coords.length; j++) {
                        if (coords[j].x == currCoord.x) {
                            covered[j] = true;
                        } else {
                            break;
                        }
                    } //change all coords with same x to true
                    success = getResult(covered, coords);

                    if (success) {
                        System.out.println("1");
                        break;
                    }
                    prevX = currCoord.x;
                }
            }
            if (!success) {
                System.out.println("0");
            }
        } else {
            System.out.println("1");
        }
    }
    private static boolean getResult(boolean[] covered, Coord[] coords) {
        TreeSet<Integer> y = new TreeSet<>();
        for (int i = 0; i < covered.length; i++) {
            if (!covered[i]) {
                y.add(coords[i].y);
            }
            if (y.size() > 2) {
                return false;
            }
        }
        return true;
    }
    static class Coord implements Comparable<Coord> {
        int x;
        int y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int compareTo(Coord a) {
            if (this.x == a.x) {
                return this.y - a.y;
            }
            return this.x - a.x;
        }
    }
}

