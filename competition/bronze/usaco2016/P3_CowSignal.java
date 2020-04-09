package bronze.usaco2016;

import java.util.*;
import java.io.*;

public class P3_CowSignal {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/cowsignal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/cowsignal.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());

        int factor = Integer.parseInt(st.nextToken());

        char[][] pattern = new char[width][height];

        for (int row = 0; row < height; row++) {
            String currRow = in.readLine();
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
                out.print(newPattern[index][row]);
            }
            out.println();
        }
        out.close();
    }
}
