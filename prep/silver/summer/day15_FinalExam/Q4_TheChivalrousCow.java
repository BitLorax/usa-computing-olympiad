package day15_Final;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q4_TheChivalrousCow {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());

        int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
        int[] dy = {2, 1, -1, -2, -2, -1, 1, 2};

        char[][] map = new char[width][height];
        Coord currPos = new Coord(0, 0, 0);
        for (int i = 0; i < height; i++) {
            String row = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
                if (row.charAt(j) == 'K'){
                    currPos.x = j;
                    currPos.y = i;
                }
            }
        }

        Queue<Coord> positions = new LinkedList<>();
        positions.add(currPos);
        boolean[][] visited = new boolean[width][height];
        while (!positions.isEmpty()) {
            currPos = positions.remove();
            if (map[currPos.x][currPos.y] == 'H') {
                System.out.println(currPos.pathLen);
                break;
            }
            if (visited[currPos.x][currPos.y]) continue;
            visited[currPos.x][currPos.y] = true;
            for (int i = 0; i < 8; i++) {
                Coord newPos = new Coord(currPos.x + dx[i], currPos.y + dy[i], currPos.pathLen + 1);
                if (newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height) continue;
                if (visited[newPos.x][newPos.y]) continue;
                if (map[newPos.x][newPos.y] == '*') continue;

                positions.add(newPos);
            }
        }
    }
    static class Coord {
        int x;
        int y;
        int pathLen;
        Coord (int x, int y, int pathLen) {
            this.x = x;
            this.y = y;
            this.pathLen = pathLen;
        }
    }
}
