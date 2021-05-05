package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Q4_Hopscotch {
    private static Set<String> combinations = new TreeSet<>();
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[][] map = new int[5][5];
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < 5; j++) {
                map[j][i] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                calcCombinations(map, j, i, "");
            }
        }
        System.out.println(combinations.size());
    }
    private static void calcCombinations(int[][] map, int x, int y, String combination) {
        if (combination.length() >= 6) {
            combinations.add(combination);
        } else {
            combination += map[x][y];
            String COMBINATION = combination;
            if (x < map.length - 1) {
                calcCombinations(map, x + 1, y, combination);
            }
            combination = COMBINATION;
            if (x > 0) {
                calcCombinations(map, x - 1, y, combination);
            }
            combination = COMBINATION;
            if (y < map.length - 1) {
                calcCombinations(map, x, y + 1, combination);
            }
            combination = COMBINATION;
            if (y > 0) {
                calcCombinations(map, x, y - 1, combination);
            }
        }
    }
}
