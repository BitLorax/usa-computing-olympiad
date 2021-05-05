package day9_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q4_BuildGates {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int instructionCount = Integer.parseInt(in.readLine());
        String moves = in.readLine();
        int gridCount = 0;
        ArrayList<Coord> coords = new ArrayList<>();
        ArrayList<Character> directions = new ArrayList<>();
        Pasture[][] map = new Pasture[2001][2001];

        System.out.println(gridCount);
    }
    static class Coord {
        int x;
        int y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static class Pasture {
        boolean left;
        boolean bottom;
    }
}
