package day9_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q2_FeedingTime {
    private static int greatestArea = 0;
    private static int currArea = 0;
    private static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
    private static int[] dy = {0, 0, 1, -1, 1, -1, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int width = Integer.parseInt(st.nextToken());
        int height = Integer.parseInt(st.nextToken());
        String[][] map = new String[width][height];
        for (int i = 0; i < height; i++) {
            String line = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = line.substring(j , j + 1);
            }
        }
        String[][] MAP = map.clone();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                getLargestPasture(map, j, i);
                currArea = 0;
                map = MAP.clone();
            }
        }
        System.out.println(greatestArea);
    }
    private static void getLargestPasture(String[][] map, int x, int y) {
        if (x < 0 || x >= map.length || y < 0 || y >= map[0].length || map[x][y].equals("*")) {
            return;
        }
        currArea++;
        greatestArea = Math.max(currArea, greatestArea);
        map[x][y] = "*";
        for (int i = 0; i < 8; i++) {
            getLargestPasture(map, x + dx[i], y + dy[i]);
        }
    }
}

