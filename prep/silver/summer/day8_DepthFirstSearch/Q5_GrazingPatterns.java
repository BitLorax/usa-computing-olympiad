package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q5_GrazingPatterns {
    private static int paths = 0;
    private static int barrenCount;
    private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        barrenCount = Integer.parseInt(in.readLine());
        int[][] map = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[j][i] = 1;
            }
        }
        for (int i = 0; i < barrenCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int y = Integer.parseInt(st.nextToken()) - 1;
            int x = Integer.parseInt(st.nextToken()) - 1;
            map[x][y] = 0;
        }
        getPaths(map, 0, 0, 0);
        System.out.println(paths);
    }
    private static void getPaths(int[][] map, int x, int y, int grassEaten) {
        if (x < 0 || x >= 5 || y < 0 || y >= 5 || map[x][y] == 0) {
            return;
        }
            grassEaten++;
            if (grassEaten == 25 - barrenCount) {
                if (x == 4 && y == 4) {
                    paths++;
                }
            }
            map[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                getPaths(map, x + dx[i], y + dy[i], grassEaten);
            }
            map[x][y] = 1;
    }
}
