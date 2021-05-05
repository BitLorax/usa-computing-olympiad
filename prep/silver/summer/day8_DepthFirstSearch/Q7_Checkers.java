package day8_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Q7_Checkers {
    private static int[] dx = {1, 1, -1, -1};
    private static int[] dy = {1, -1, 1, -1};
    private static int enemyCount = 0;
    private static ArrayList<Coord> positions = new ArrayList<>();
    private static ArrayList<Coord> moves = new ArrayList<>();
    private static char[][] map;
    private static boolean complete = false;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        map = new char[len][len];
        for (int i = 0; i < len; i++) {
            String line = in.readLine();
            for (int j = 0; j < len; j++) {
                char k = line.charAt(j);
                map[j][i] = k;
                if (k == 'o') {
                    enemyCount++;
                }
                if (k == 'K') {
                    positions.add(new Coord(j, i));
                }
            }
        }
        /*
        for (int i = 0; i < positions.size(); i++) {
            getMoves(map, positions.get(i)[0], positions.get(i)[1], 0);
            xAns = new ArrayList<>();
            yAns = new ArrayList<>();
        }
        */
        for (int i = 0; i < positions.size(); i++) {
            getMoves(positions.get(i).x, positions.get(i).y, 0);
            if (complete) {
                break;
            } else {
                moves = new ArrayList<>();
            }
        }
        for (int i = 0; i < moves.size(); i++) {
            moves.get(i).print();
        }
    }
    private static void getMoves(int x, int y, int defeated) {
        if (defeated == enemyCount) {
            complete = true;
            moves.add(new Coord(y + 1, x + 1));
            return;
        }
        for (int i = 0; i < 4; i++) {
            int enemyX = x + dx[i];
            int enemyY = y + dy[i];
            int proposedX = enemyX + dx[i];
            int proposedY = enemyY + dy[i];
            if (proposedX >= 0 && proposedX < map.length && proposedY >= 0 && proposedY < map.length) {
                if (map[enemyX][enemyY] == 'o') {
                    defeated++;
                    map[enemyX][enemyY] = '#';
                    moves.add(new Coord(y + 1, x + 1));
                    getMoves(proposedX, proposedY, defeated);
                    if (complete) {
                        break;
                    }
                    moves.remove(new Coord(y + 1, x + 1));
                    map[enemyX][enemyY] = 'o';
                    defeated--;
                }
            }
        }
    }
    static class Coord {
        int x;
        int y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
        void print() {
            System.out.println(x + " " + y);
        }
    }
}
