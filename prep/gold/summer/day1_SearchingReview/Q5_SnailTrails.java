package day1_SearchingReview;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Q5_SnailTrails {
    private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    private static int len;
    private static int maxVisited = 0;
    private static boolean[][] grid;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        len = Integer.parseInt(st.nextToken());
        int barrierCount = Integer.parseInt(st.nextToken());
        grid = new boolean[len][len];
        for (int i = 0; i < barrierCount; i++) {
            String pos = in.readLine();
            grid[pos.charAt(0) - 'A'][Integer.parseInt(pos.substring(1, pos.length())) - 1] = true;
        }
        getTrail(0, 0, new boolean[len][len], 1);
        System.out.println(maxVisited);
    }

    private static void getTrail(int x, int y, boolean[][] visited, int moves) {
        if (x < 0 || x >= len || y < 0 || y >= len) return;
        visited[x][y] = true;
        int X = x;
        int Y = y;
        int MOVES = moves;
        for (int i = 0; i < 4; i++) {
            x = X;
            y = Y;
            moves = MOVES;
            int steps = 1;
            while (x + dx[i] * steps >= 0 & x + dx[i] * steps < len && y + dy[i] * steps >= 0 && y + dy[i] * steps < len && !grid[x + dx[i] * steps][y + dy[i] * steps] && !visited[x + dx[i] * steps][y + dy[i] * steps]) {
                visited[x - dx[i] + dx[i] * steps][y - dy[i] + dy[i] * steps] = true;
                steps++;
            }
            steps--;
            x += dx[i] * steps;
            y += dy[i] * steps;
            moves += steps;
            if (x + dx[i] >= 0 && x + dx[i] < len && y + dy[i] >= 0 && y + dy[i] < len && visited[x + dx[i]][y + dy[i]]) { //ran into self
                maxVisited = Math.max(maxVisited, moves);
                continue;
            }
            if (steps != 0) {
                getTrail(x, y, clone(visited), moves);
            }
            for (int j = 0; j < steps; j++) {
                visited[x - dx[i] * j][y - dy[i] * j] = false;
            }
        }
    }

    private static boolean[][] clone(boolean[][] in) {
        boolean[][] out = new boolean[in.length][in[0].length];
        for (int i = 0; i < in.length; i++) {
            out[i] = in[i].clone();
        }
        return out;
    }
}
