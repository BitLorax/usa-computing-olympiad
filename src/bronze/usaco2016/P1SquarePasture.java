package bronze.usaco2016;

/*

[Explanation]
Find the smallest integers for both x and y, then subtract them to get the greatest length.
Compare the two lengths and square the biggest one.

 */

import java.util.*;
import java.io.*;

public class P1SquarePasture {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("src/bronze/resources/square.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/bronze/resources/square.out")));

        int smallestX = 11;
        int smallestY = 11;
        int largestX = 0;
        int largestY = 0;
        int largestLength = 0;

        for (int fileRow = 0; fileRow < 2; fileRow++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
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

        pw.println(largestLength * largestLength);
        pw.close();
    }

}
