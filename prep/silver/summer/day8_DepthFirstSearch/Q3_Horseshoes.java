package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q3_Horseshoes {
    private static int maxHorseshoes = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(in.readLine());
        int[][] map = new int[size][size];
        for (int i = 0; i < size; i++) {
            String line = in.readLine();
            for (int j = 0; j < size; j++) {
                if (line.substring(j, j + 1).equals("(")) {
                    map[j][i] = 1;
                } else {
                    map[j][i] = -1;
                }
            }
        }
        System.out.println(traverse(map, 0, 0, 0, 0, false, new boolean[size][size]));
    }
    private static int traverse(int[][] map, int x, int y, int currSum, int currHorseshoes, boolean switched, boolean[][] mapTaken) {
        if (currSum == 0 && switched) {
            return Math.max(currHorseshoes, maxHorseshoes);
        }
        if (mapTaken[x][y]) {
            return 0;
        }
        if (map[x][y] == 1 && switched) {
            return 0;
        }
        int currHorseshoe = map[x][y];
        switched = map[x][y] == -1;
        mapTaken[x][y] = true;
        currSum += currHorseshoe;
        currHorseshoes++;

        int X = x;
        int Y = y;
        int CURR_SUM = currSum;
        int CURR_HORSESHOES = currHorseshoes;
        boolean SWITCHED = switched;

        if (x < map.length - 1) {
            maxHorseshoes = Math.max(traverse(map, x + 1, y, currSum, currHorseshoes, switched, mapTaken.clone()), maxHorseshoes);
        }
        x = X;
        y = Y;
        currSum = CURR_SUM;
        currHorseshoes = CURR_HORSESHOES;
        switched = SWITCHED;
        if (x > 0) {
            maxHorseshoes = Math.max(traverse(map, x - 1, y, currSum, currHorseshoes, switched, mapTaken.clone()), maxHorseshoes);
        }
        x = X;
        y = Y;
        currSum = CURR_SUM;
        currHorseshoes = CURR_HORSESHOES;
        switched = SWITCHED;
        if (y < map.length - 1) {
            maxHorseshoes = Math.max(traverse(map, x, y + 1, currSum, currHorseshoes, switched, mapTaken.clone()), maxHorseshoes);
        }
        x = X;
        y = Y;
        currSum = CURR_SUM;
        currHorseshoes = CURR_HORSESHOES;
        switched = SWITCHED;
        if (y > 0) {
            maxHorseshoes = Math.max(traverse(map, x, y - 1, currSum, currHorseshoes, switched, mapTaken.clone()), maxHorseshoes);
        }
        mapTaken[x][y] = false;
        return maxHorseshoes;
    }
}
