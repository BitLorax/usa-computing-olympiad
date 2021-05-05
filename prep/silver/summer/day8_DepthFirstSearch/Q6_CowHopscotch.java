package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q6_CowHopscotch {
    private static int paths = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());
        char[][] map = new char[width][height];
        for (int i = 0; i < height; i++) {
            String line = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = line.charAt(j);
            }
        }
        jump(map, 0, 0);
        System.out.println(paths);
    }
    private static void jump(char[][] map, int x, int y) {
        if (x < 0 || x >= map.length || y < 0 || y >= map[0].length) {
            return;
        }
        if (x == map.length - 1 && y == map[0].length - 1) {
            paths++;
            return;
        }
        for (int i = x + 1; i < map.length; i++) {
            for (int j = y + 1; j < map[0].length; j++) {
                if (map[i][j] != map[x][y]) {
                    jump(map, i, j);
                }
            }
        }
    }
}
