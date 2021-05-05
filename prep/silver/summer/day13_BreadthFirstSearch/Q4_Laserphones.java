package day13_BreadthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q4_Laserphones {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        char[][] map = new char[width][height];
        Coord currPos = new Coord(0, 0, 0, 'N');
        for (int i = 0; i < height; i++) {
            String row = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
                if (row.charAt(j) == 'C') {
                    currPos = new Coord(j, i, 0, 'N');
                }
            }
        }

        Coord start = new Coord(currPos.x, currPos.y, 0, 'N');
        Queue<Coord> positions = new LinkedList<>();
        positions.add(currPos);
        boolean[][] visited = new boolean[width][height];

        while (!positions.isEmpty()) {
            currPos = positions.remove();

            if (map[currPos.x][currPos.y] == 'C' && !(currPos.x == start.x && currPos.y == start.y)) {
                System.out.println(currPos.mirrorsUsed - 1);
                break;
            } //end case

            if (visited[currPos.x][currPos.y]) continue;
            visited[currPos.x][currPos.y] = true;

            for (int i = 0; i < 4; i++) { //right left down up
                Coord newPos = new Coord(currPos.x, currPos.y, currPos.mirrorsUsed + 1, currPos.direc);
                switch (i) {
                    case 0: newPos.direc = 'R';
                    break;
                    case 1: newPos.direc = 'L';
                    break;
                    case 2: newPos.direc = 'D';
                    break;
                    case 3: newPos.direc = 'U';
                    break;
                }
                while (true) {
                    newPos = new Coord(newPos.x + dx[i], newPos.y + dy[i], newPos.mirrorsUsed, newPos.direc);
                    if (newPos.x < 0 || newPos.x >= map.length || newPos.y < 0 || newPos.y >= map[0].length) break;
                    if (map[newPos.x][newPos.y] == '*') break;
                    if (visited[newPos.x][newPos.y]) continue;
                    positions.add(newPos);
                }
            }
        }
    }
    static class Coord {
        int x;
        int y;
        char direc;
        int mirrorsUsed;
        Coord (int x, int y, int mirrorsUsed, char direc) {
            this.x = x;
            this.y = y;
            this.mirrorsUsed = mirrorsUsed;
            this.direc = direc;
        }
    }
}
