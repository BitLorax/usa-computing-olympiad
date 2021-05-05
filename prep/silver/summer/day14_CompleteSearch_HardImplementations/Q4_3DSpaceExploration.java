package day14_CompleteSearch_HardImplementations;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Q4_3DSpaceExploration {
    private static char[][][] space;
    private static boolean[][][] visited;
    private static int len;
    private static int[] dx = {1, -1, 0, 0, 0, 0};
    private static int[] dy = {0, 0, 1, -1, 0, 0};
    private static int[] dz = {0, 0, 0, 0, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        len = Integer.parseInt(in.readLine());
        space = new char[len][len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                String row = in.readLine();
                for (int k = 0; k < len; k++) {
                    space[i][j][k] = row.charAt(k);
                }
            }
        }
        visited = new boolean[len][len][len];

        int asteriodCount = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < len; k++) {
                    if (space[i][j][k] == '*' && !visited[i][j][k]) {
                        asteriodCount++;
                        Queue<Coord> positions = new LinkedList<>();
                        positions.add(new Coord(k, j, i));
                        while (!positions.isEmpty()) {
                            Coord currCoord = positions.remove();
                            if (visited[currCoord.z][currCoord.y][currCoord.x]) continue;
                            visited[currCoord.z][currCoord.y][currCoord.x] = true;
                            for (int l = 0; l < 6; l++) {
                                Coord newCoord = new Coord(currCoord.x + dx[l], currCoord.y + dy[l], currCoord.z + dz[l]);
                                if (newCoord.x < 0 || newCoord.x >= len || newCoord.y < 0 || newCoord.y >= len || newCoord.z < 0 || newCoord.z >= len) continue;
                                if (visited[newCoord.z][newCoord.y][newCoord.x]) continue;
                                if (space[newCoord.z][newCoord.y][newCoord.x] == '*') {
                                    positions.add(newCoord);
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println(asteriodCount);
    }
    static class Coord {
        int x;
        int y;
        int z;
        Coord (int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}
