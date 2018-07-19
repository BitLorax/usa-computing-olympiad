package bronze.usaco2016;

import java.io.*;

public class P3CowTipping {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/cowtip.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/cowtip.out")));

        int sideLength = Integer.parseInt(in.readLine());

        int[][] grid = new int[sideLength][sideLength];
        for (int row = 0; row < sideLength; row++) {
            String currRow = in.readLine();
            for (int index = 0; index < sideLength; index++) {
                grid[index][row] = Character.getNumericValue(currRow.charAt(index));
            }
        }

        int changes = 0;

        for (int y = sideLength - 1; y >= 0; y--) {
            for (int x = sideLength - 1; x >= 0; x--) {
                if (grid[y][x] == 1) {
                    changes++;
                    for (int sideToY = y; sideToY >= 0; sideToY--) {
                        for (int sideToX = x; sideToX >= 0; sideToX--) {
                            if (grid[sideToY][sideToX] == 1) {
                                grid[sideToY][sideToX] = 0;
                            } else {
                                grid[sideToY][sideToX] = 1;
                            }
                        }
                    }
                }
            }
        }

        out.println(changes);
        out.close();
    }
}
