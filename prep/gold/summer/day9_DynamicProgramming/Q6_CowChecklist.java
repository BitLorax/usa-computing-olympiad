package day9_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q6_CowChecklist {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int hCount = Integer.parseInt(st.nextToken());
        int gCount = Integer.parseInt(st.nextToken());
        Coord[] hPositions = new Coord[hCount];
        Coord[] gPositions = new Coord[gCount];
        for (int i = 0; i < hCount; i++) {
            st = new StringTokenizer(in.readLine());
            hPositions[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        for (int i = 0; i < gCount; i++) {
            st = new StringTokenizer(in.readLine());
            gPositions[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        int[][][] states = new int[hCount + 1][gCount + 1][2];
        for (int i = 0; i <= hCount; i++) {
            for (int j = 0; j <= gCount; j++) {
                states[i][j][0] = 2000000000;
                states[i][j][1] = 2000000000;
            }
        }
        states[1][0][0] = 0;
        for (int i = 0; i <= hCount; i++) {
            for (int j = 0; j <= gCount; j++) {
                for (int k = 0; k < 2; k++) {
                    if ((i == 0 && k == 0) || (k == 1 && j == 0)) continue; //impossible states
                    Coord from;
                    if (k == 0) from = hPositions[i - 1]; //0 indexed, dp[1][a][b] would include Holstein at index 0
                    else from = gPositions[j - 1];
                    if (i < hCount) { //if there is a next Holstein
                        states[i + 1][j][0] = Math.min(states[i + 1][j][0], states[i][j][k] + getDist(from, hPositions[i]));
                    }
                    if (j < gCount) { //if there is a next Guernsey
                        states[i][j + 1][1] = Math.min(states[i][j + 1][1], states[i][j][k] + getDist(from, gPositions[j]));
                    }
                }
            }
        }
        System.out.println(states[hCount][gCount][0]);
    }
    private static int getDist(Coord a, Coord  b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    static class Coord {
        int x;
        int y;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
