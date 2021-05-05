package day13_BreadthFirstSearch;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q1_SatellitePhotographsII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        char[][] map = new char[width][height];
        for (int i = 0; i < height; i++) {
            String row = in.nextLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
            }
        }

        int maxPastures = 0;
        boolean[][] visited = new boolean[width][height];
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (map[i][j] == '*' && !visited[i][j]) {
                    Queue<Integer[]> positions = new LinkedList<>();
                    Integer[] temp = {i, j};
                    positions.add(temp);
                    int pastures = 0;
                    while (!positions.isEmpty()) {
                        Integer[] currPos = positions.remove();
                        if (visited[currPos[0]][currPos[1]]) continue;
                        visited[currPos[0]][currPos[1]] = true;
                        pastures++;
                        for (int k = 0; k < 4; k++) {
                            temp = new Integer[2];
                            temp[0] = currPos[0] + dx[k];
                            temp[1] = currPos[1] + dy[k];
                            if (temp[0] < 0 || temp[0] >= map.length || temp[1] < 0 || temp[1] >= map[0].length) continue;
                            if (visited[temp[0]][temp[1]]) continue;
                            if (map[temp[0]][temp[1]] == '.') continue;
                            positions.add(temp);
                        }
                    }
                    maxPastures = Math.max(maxPastures, pastures);
                }
            }
        }
        System.out.println(maxPastures);
    }
}
