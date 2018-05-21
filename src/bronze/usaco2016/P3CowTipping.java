package bronze.usaco2016;

/*

[Explanation]
The best approach to this problem is to start from the bottom right corner and going left and up.
Whenever a tipped cow is approached, flip all the cows from the top left corner to the current cow.
Repeating this would eventually result in all normal cows.

Example (1 is tipped, x stands for changed positions):
001     111     001     110     000
000     110     000     000     000
110     000     000     000     000

ooo     xxo     xxo     xxx     xxo
ooo     xxo     xxo     ooo     ooo
ooo     xxo     ooo     ooo     ooo

 */

import java.io.*;

public class P3CowTipping {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/bronze/resources/cowtip.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources/cowtip.out")));

        int sideLength = Integer.parseInt(br.readLine());

        int[][] grid = new int[sideLength][sideLength];
        for (int row = 0; row < sideLength; row++) {
            String currRow = br.readLine();
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

        pw.println(changes);
        pw.close();
    }
}
