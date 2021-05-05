package day1_SearchingReview;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q4_Overfencing {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken()) * 2 + 1;
        int height = Integer.parseInt(st.nextToken()) * 2 + 1;

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        char[][] maze = new char[width][height];
        Coord[] exits = new Coord[2];
        int k = 0;
        for (int i = 0; i < height; i++) {
            String row = in.readLine();
            if (row == null) {
                for (int j = 0; j < width; j++) {
                    maze[j][i] = ' ';
                }
            } else {
                for (int j = 0; j < width; j++) {
                    maze[j][i] = row.charAt(j);
                    if (row.charAt(j) == ' ' && ((j == 0 || j == width - 1) || (i == 0 || i == height - 1))) {
                        exits[k] = new Coord(j, i, 0);
                        k++;
                    }
                }
            }
        }
        int[][][] distanceFromExit = new int[width][height][2]; //for both exits
        for (int i = 0; i < 2; i++) { //run bfs on both exits
            Queue<Coord> positions = new LinkedList<>();
            boolean[][] visited = new boolean[width][height];
            if (exits[i].x == 0) {
                exits[i].x++;
            } else if (exits[i].x == width - 1) {
                exits[i].x--;
            } else if (exits[i].y == 0) {
                exits[i].y++;
            } else {
                exits[i].y--;
            }
            positions.add(exits[i]);
            while (!positions.isEmpty()) {
                Coord currPos = positions.remove();
                if (currPos.x < 0 || currPos.x >= width || currPos.y < 0 || currPos.y >= height) continue;
                if (visited[currPos.x][currPos.y]) continue;
                visited[currPos.x][currPos.y] = true;
                distanceFromExit[currPos.x][currPos.y][i] = currPos.moves;
                for (int j = 0; j < 4; j++) {
                    Coord newPos = new Coord(currPos.x + 2 * dx[j], currPos.y + 2 * dy[j], currPos.moves + 1);
                    if (newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height) continue;
                    if (maze[newPos.x - dx[j]][newPos.y - dy[j]] != ' ') continue;
                    positions.add(newPos);
                }
            }
        }
        int maxDist = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                maxDist = Math.max(maxDist, Math.min(distanceFromExit[i][j][0], distanceFromExit[i][j][1]));
            }
        }

        System.out.println(maxDist + 1);

    }
    static class Coord {
        int x;
        int y;
        int moves;
        Coord (int x, int y, int moves) {
            this.x = x;
            this.y = y;
            this.moves = moves;
        }
    }
}
