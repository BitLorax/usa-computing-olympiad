package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q8_Perimeter {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int haybaleCount = Integer.parseInt(in.readLine());
        int[][] field = new int[102][102]; //102 to compensate for "walking" when a haybale is at the edge
        int[] currPos = {Integer.MAX_VALUE, Integer.MAX_VALUE};
        for (int i = 0; i < haybaleCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            field[x][y] = 1;
            if (x < currPos[0]) {
                currPos[0] = x;
                currPos[1] = y;
            }
        }
        currPos[0] -= 1;
        int[] start = currPos.clone();
        int perimeter = 0;
        int direc = 0; //index of direction in movePriorities
        char[] movePriorities = {'u', 'r', 'd', 'l'};
        while (true) {
            int[] result = getNextMove(field, currPos, direc, movePriorities);
            char move = movePriorities[result[0]];
            direc = result[0];
            perimeter += result[1];
            switch (move) {
                case 'u':
                    currPos[1] -= 1;
                    break;
                case 'r':
                    currPos[0] += 1;
                    break;
                case 'd':
                    currPos[1] += 1;
                    break;
                case 'l':
                    currPos[0] -= 1;
                    break;
            }
            if (Arrays.equals(start, currPos)) {
                break;
            }
        }
        System.out.println(perimeter);
    }
    private static int[] getNextMove(int[][] field, int[] currPos, int direc, char[] movePriorities) { //index 0 is direction, 1 is numbers of blocks
        direc = (direc + 1) % 4;
        int blocked = 0;
        while (checkIfBlocked(field, currPos, movePriorities[direc])) {
            direc = direc - 1;
            if (direc < 0) {
                direc += 4;
            }
            blocked++;
        }
        int[] result = new int[2];
        result[0] = direc;
        result[1] = blocked;
        return result;
    }
    private static boolean checkIfBlocked(int[][] field, int[] currPos, char side) {
        switch (side) {
            case 'u': return currPos[1] == 0 || field[currPos[0]][currPos[1] - 1] == 1;
            case 'r': return currPos[0] == 101 || field[currPos[0] + 1][currPos[1]] == 1;
            case 'd': return currPos[1] == 101 || field[currPos[0]][currPos[1] + 1] == 1;
            case 'l': return currPos[0] == 0 || field[currPos[0] - 1][currPos[1]] == 1;
        }
        System.out.println("ERROR: checkIfBlocked");
        return false;
    }
}
