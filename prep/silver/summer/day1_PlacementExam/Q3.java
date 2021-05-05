package placement;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());

        String[][] map = new String[width][height];
        for (int i = 0; i < height; i++) {
            String row = in.nextLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.substring(j, j + 1);
            }
        }
        ArrayList<Integer> results = new ArrayList<>();
        results = traverse(map, width - 1, height - 1, 0, results, width, height, "NULL");
        System.out.println(results.toString());
    }
    private static ArrayList<Integer> traverse(String[][] map, int x, int y, int grass, ArrayList<Integer> results, int width, int height, String lastmove) {
        if (x == 0 && y == 0) {
            results.add(grass);
        }
        switch(lastmove) {
            case "U":
                if (y != 0 && (map[x][y - 1].equals(".") || map[x][y - 1].equals("B"))) {
                    traverse(map, x, y - 1, grass++, results, width, height, "U");
                }
                if (x != 0 && (map[x - 1][y].equals(".") || map[x - 1][y].equals("B"))) {
                    traverse(map, x - 1, y, grass++, results, width, height, "L");
                }
                if (x != width - 1 && (map[x + 1][y].equals(".") || map[x + 1][y].equals("B"))) {
                    traverse(map, x + 1, y, grass++, results, width, height, "R");
                }
                if (y != height - 1 && (map[x][y + 1].equals(".") || map[x][y + 1].equals("B"))) {
                    traverse(map, x, y + 1, grass++, results, width, height, "D");
                }
                break;
            case "D":
                if (x != 0 && (map[x - 1][y].equals(".") || map[x - 1][y].equals("B"))) {
                    traverse(map, x - 1, y, grass++, results, width, height, "L");
                }
                if (x != width - 1 && (map[x + 1][y].equals(".") || map[x + 1][y].equals("B"))) {
                    traverse(map, x + 1, y, grass++, results, width, height, "R");
                }
                if (y != height - 1 && (map[x][y + 1].equals(".") || map[x][y + 1].equals("B"))) {
                    traverse(map, x, y + 1, grass++, results, width, height, "D");
                }
                if (y != 0 && (map[x][y - 1].equals(".") || map[x][y - 1].equals("B"))) {
                    traverse(map, x, y - 1, grass++, results, width, height, "U");
                }
                break;
            case "L":
                if (x != 0 && (map[x - 1][y].equals(".") || map[x - 1][y].equals("B"))) {
                    traverse(map, x - 1, y, grass++, results, width, height, "L");
                }
                if (y != height - 1 && (map[x][y + 1].equals(".") || map[x][y + 1].equals("B"))) {
                    traverse(map, x, y + 1, grass++, results, width, height, "D");
                }
                if (y != 0 && (map[x][y - 1].equals(".") || map[x][y - 1].equals("B"))) {
                    traverse(map, x, y - 1, grass++, results, width, height, "U");
                }
                if (x != width - 1 && (map[x + 1][y].equals(".") || map[x + 1][y].equals("B"))) {
                    traverse(map, x + 1, y, grass++, results, width, height, "R");
                }
                break;
            case "R":
                if (y != height - 1 && (map[x][y + 1].equals(".") || map[x][y + 1].equals("B"))) {
                    traverse(map, x, y + 1, grass++, results, width, height, "D");
                }
                if (y != 0 && (map[x][y - 1].equals(".") || map[x][y - 1].equals("B"))) {
                    traverse(map, x, y - 1, grass++, results, width, height, "U");
                }
                if (x != width - 1 && (map[x + 1][y].equals(".") || map[x + 1][y].equals("B"))) {
                    traverse(map, x + 1, y, grass++, results, width, height, "R");
                }
                if (x != 0 && (map[x - 1][y].equals(".") || map[x - 1][y].equals("B"))) {
                    traverse(map, x - 1, y, grass++, results, width, height, "L");
                }
                break;
            case "NULL":
                if (y != 0 && (map[x][y - 1].equals(".") || map[x][y - 1].equals("B"))) {
                    traverse(map, x, y - 1, grass++, results, width, height, "U");
                }
                if (x != 0 && (map[x - 1][y].equals(".") || map[x - 1][y].equals("B"))) {
                    traverse(map, x - 1, y, grass++, results, width, height, "L");
                }
                if (x != width - 1 && (map[x + 1][y].equals(".") || map[x + 1][y].equals("B"))) {
                    traverse(map, x + 1, y, grass++, results, width, height, "R");
                }
                if (y != height - 1 && (map[x][y + 1].equals(".") || map[x][y + 1].equals("B"))) {
                    traverse(map, x, y + 1, grass++, results, width, height, "D");
                }
                break;
        }

        return results;
    }
}
