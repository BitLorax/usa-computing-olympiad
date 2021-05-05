package day12_BreadthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q3_Munching {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        char[][] map = new char[width][height];
        Integer[] currPos = new Integer[3];
        for (int i = 0; i < height; i++) {
            String row = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
                if (row.charAt(j) == 'B') {
                    currPos[0] = j;
                    currPos[1] = i;
                    currPos[2] = 0;
                }
            }
        }
        int shortestPath = Integer.MAX_VALUE;
        Queue<Integer[]> positions = new LinkedList<>();
        positions.add(currPos);
        boolean[][] visited = new boolean[width][height];
        while (!positions.isEmpty()) {
            currPos = positions.remove();
            if (currPos[0] < 0 || currPos[0] >= map.length || currPos[1] < 0 || currPos[1] >= map[0].length) {
                continue;
            }
            if (visited[currPos[0]][currPos[1]]) {
                continue;
            }
            if (map[currPos[0]][currPos[1]] == 'C') {
                shortestPath = Math.min(currPos[2], shortestPath);
            }
            if (map[currPos[0]][currPos[1]] != '.' && map[currPos[0]][currPos[1]] != 'B') {
                continue;
            }
            visited[currPos[0]][currPos[1]] = true;
            for (int i = 0; i < 4; i++) {
                Integer[] newPos = {currPos[0] + dx[i], currPos[1] + dy[i], currPos[2] + 1};
                positions.add(newPos);
            }
        }
        System.out.println(shortestPath);
    }
}
