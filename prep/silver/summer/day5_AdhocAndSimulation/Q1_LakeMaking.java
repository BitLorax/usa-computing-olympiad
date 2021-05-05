package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1_LakeMaking {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int waterLevel = Integer.parseInt(st.nextToken());
        int instructionCount = Integer.parseInt(st.nextToken());

        int[][] lake = new int[width][height];
        for (int i = 0; i < height; i++) {
            st = new StringTokenizer(in.readLine());
            for (int j = 0; j < width; j++) {
                lake[j][i] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < instructionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int y = Integer.parseInt(st.nextToken()) - 1;
            int x = Integer.parseInt(st.nextToken()) - 1;
            int stomp = Integer.parseInt(st.nextToken());

            int max = getMax(lake, x, y);
            int newElev = max - stomp;
            for (int j = x; j < x + 3; j++) {
                for (int k = y; k < y + 3; k++) {
                    if (lake[j][k] > newElev) {
                        lake[j][k] = newElev;
                    }
                }
            }
        }
        int total = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int newHeight = (lake[j][i] - waterLevel) * -1;
                if (newHeight > 0) {
                    total+= newHeight;
                }
            }
        }

        System.out.println(total * 72 * 72);
    }
    private static int getMax(int[][] lake, int x, int y) {
        int max = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                max = Math.max(lake[i][j], max);
            }
        }
        return max;
    }
}
