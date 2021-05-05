package day5_Graphs;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q8_TheGrove {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        boolean[][] grove = new boolean[width][height];
        int leastUp = Integer.MAX_VALUE; //if passed this y line, circled grove
        int leastRight = Integer.MAX_VALUE;
        int startX = -1;
        int startY = -1;
        for (int i = 0; i < height; i++) {
            String row =  in.readLine();
            for (int j = 0; j < width; j++) {
                if (row.charAt(j) == 'X') {
                    leastUp = Math.min(leastUp, i);
                    grove[j][i] = true;
                } else if (row.charAt(j) == '*') {
                    startX = j;
                    startY = i;
                }
            }
        }
        boolean pastGrove = false;
        for (int i = 0; i < width; i++) {
            if (pastGrove && !grove[i][leastUp]) leastRight = Math.min(leastRight, i);
            if (grove[i][leastUp]) {
                pastGrove = true;
                leastRight = Integer.MAX_VALUE;
            }
        }
        int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
        int[] dy = {0, 0, 1, -1, 1, -1, 1, -1};

        int[][][] distances = new int[width][height][2];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                distances[i][j][0] = Integer.MAX_VALUE;
                distances[i][j][1] = Integer.MAX_VALUE;
            }
        }
        distances[startX][startY][0] = 0;
        Queue<Coord> positions = new LinkedList<>();
        positions.add(new Coord(startX, startY, 0, 0));
        while (!positions.isEmpty()) {
            Coord currPos = positions.remove();
            for (int i = 0; i < 8; i++) {
                Coord newPos = new Coord(currPos.x + dx[i], currPos.y + dy[i], currPos.dist + 1, currPos.passedLine);
                if (newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height) continue;
                if (grove[newPos.x][newPos.y]) continue;
                if (currPos.y == leastUp && newPos.y == leastUp - 1 && currPos.x >= leastRight) continue;
                if (currPos.y == leastUp - 1 && newPos.y == leastUp && newPos.x >= leastRight) newPos.passedLine = 1;
                if (distances[newPos.x][newPos.y][newPos.passedLine] <= newPos.dist) continue;
                distances[newPos.x][newPos.y][newPos.passedLine] = newPos.dist;
                positions.add(newPos);
            }
        }
        System.out.println(distances[startX][startY][1]);
    }
    static class Coord {
        int x;
        int y;
        int dist;
        int passedLine;
        Coord (int x, int y, int dist, int pl) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.passedLine = pl;
        }
    }
}
