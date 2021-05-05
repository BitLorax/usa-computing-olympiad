package day9_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")

public class Q3_SwitchingOnTheLights {
    private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    private static int maxOn = 1;
    private static ArrayList<Coord>[][] commandMap;
    private static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int len = Integer.parseInt(st.nextToken());
        int commandCount = Integer.parseInt(st.nextToken());
        boolean[][] map = new boolean[len][len];
        visited = new boolean[len][len];
        commandMap = new ArrayList[len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                commandMap[i][j] = new ArrayList<>();
            }
        }
        map[0][0] = true;
        for (int i = 0; i < commandCount; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            commandMap[x][y].add(new Coord(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1));
        }

        move(map, 0, 0);
        System.out.println(maxOn);
    }
    private static void move(boolean[][] map, int x, int y) {
        if (x < 0 || x >= map.length || y < 0 || y >= map.length) {
            return;
        }
        if (visited[x][y] || !map[x][y]) {
            return;
        }

        visited[x][y] = true;
        for (int i = 0; i < commandMap[x][y].size(); i++) {
            Coord targetCoord = commandMap[x][y].get(i);
            if (!map[targetCoord.x][targetCoord.y]) {
                map[targetCoord.x][targetCoord.y] = true;
                maxOn++;
            }
            if (nextToVisited(visited, targetCoord.x, targetCoord.y)) {
                move(map, targetCoord.x, targetCoord.y); //able to go to that room, jump to it bc the path to it is visited
            }
        }
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] >= 0 && x + dx[i] < map.length && y + dy[i] >= 0 && y + dy[i] < map.length) {
                if (map[x + dx[i]][y + dy[i]]) {
                    move(map, x + dx[i], y + dy[i]); //visit all 4 adjacent rooms
                }
            }
        }
    }
    private static boolean nextToVisited(boolean[][] visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int testX = x + dx[i];
            int testY = y + dy[i];
            if (testX >= 0 && testX < visited.length && testY >= 0 && testY < visited.length) {
                if (visited[testX][testY]) {
                    return true;
                }
            }
        }
        return false;
    }
    static class Coord {
        int x;
        int y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
