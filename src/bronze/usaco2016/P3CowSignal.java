package bronze.usaco2016;

/*

[Explanation]
Create a list of the information, and using the distance formula, add booleans to another 2d list determined if horozontal can connect to vertical.
Then, make a recursive method that accumulates values based on whether a cow can communicate to another.
Finally, take the greatest chain from all possible starting points.

 */

import java.util.*;
import java.io.*;

public class P3CowSignal {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("src/bronze/resources/cowsignal.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources/cowsignal.out")));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());

        int factor = Integer.parseInt(st.nextToken());

        char[][] pattern = new char[width][height];

        for (int row = 0; row < height; row++) {
            String currRow = br.readLine();
            for (int index = 0; index < currRow.length(); index++) {
                pattern[index][row] = currRow.charAt(index);
            }
        }

        char[][] newPattern = new char[width * factor][height * factor];

        for (int row = 0; row < height; row++) {
            for (int index = 0; index < width; index++) {
                for (int repeatRow = 0; repeatRow < factor; repeatRow++) {
                    for (int repeatIndex = 0; repeatIndex < factor; repeatIndex++) {
                        newPattern[index * factor + repeatIndex][row * factor + repeatRow] = pattern[index][row];
                    }
                }
            }
        }

        for (int row = 0; row < height * factor; row++) {
            for (int index = 0; index < width * factor; index++) {
                pw.print(newPattern[index][row]);
            }
            pw.println();
        }
        pw.close();
    }
}
