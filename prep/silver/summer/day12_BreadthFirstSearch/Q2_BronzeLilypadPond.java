package day12_BreadthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q2_BronzeLilypadPond {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int move1 = Integer.parseInt(st.nextToken());
        int move2 = Integer.parseInt(st.nextToken());

        int[] dx = {move1, move1, -1 * move1, -1 * move1, move2, -1 * move2, move2, -1 * move2};
        int[] dy = {move2, -1 * move2, move2, -1 * move2, move1, move1, -1 * move1, -1 * move1};

        int[][] map = new int[width][height];
        Integer[] currPos = new Integer[3];
        for (int i = 0; i < height; i++) {
            st = new StringTokenizer(in.readLine());
            for (int j = 0; j < width; j++) {
                int k = Integer.parseInt(st.nextToken());
                if (k == 3) {
                    currPos[0] = j;
                    currPos[1] = i;
                    currPos[2] = 0;
                }
                map[j][i] = k;
            }
        }
        Queue<Integer[]> positions = new LinkedList<>();
        positions.add(currPos);
        int moves = Integer.MAX_VALUE;
        boolean[][] visited = new boolean[width][height];
        while (!positions.isEmpty()) {
            currPos = positions.remove();
            if (currPos[0] < 0 || currPos[0] >= map.length || currPos[1] < 0 || currPos[1] >= map[0].length) {
                continue;
            }
            if (map[currPos[0]][currPos[1]] == 4) {
                moves = Math.min(moves, currPos[2]);
                break;
            }
            if (visited[currPos[0]][currPos[1]] || (map[currPos[0]][currPos[1]] != 1 && map[currPos[0]][currPos[1]] != 3)) {
                continue;
            }
            visited[currPos[0]][currPos[1]] = true;
            for (int i = 0; i < 8; i++) {
                Integer[] newPos = {currPos[0] + dx[i], currPos[1] + dy[i], currPos[2] + 1};
                positions.add(newPos);
            }
        }
        System.out.println(moves);
    }
}
