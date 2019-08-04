package bronze.usaco2016;

import java.util.*;
import java.io.*;

public class P1_SquarePasture {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("src/bronze/resources2016/square.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources2016/square.out")));

        int smallestX = 11;
        int smallestY = 11;
        int largestX = 0;
        int largestY = 0;
        int largestLength = 0;

        for (int fileRow = 0; fileRow < 2; fileRow++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int coords = 0; coords < 2; coords++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                if (x < smallestX) {
                    smallestX = x;
                }

                if (x > largestX) {
                    largestX = x;
                }

                if (y < smallestY) {
                    smallestY = y;
                }

                if (y > largestY) {
                    largestY = y;
                }

            }
        }

        largestLength = largestX - smallestX;
        if (largestY - smallestY > largestLength) {
            largestLength = largestY - smallestY;
        }

        out.println(largestLength * largestLength);
        out.close();
    }

}
