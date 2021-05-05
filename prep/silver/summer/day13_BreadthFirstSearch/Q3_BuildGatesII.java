package day13_BreadthFirstSearch;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Q3_BuildGatesII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int moveCount = Integer.parseInt(in.nextLine());
        String moves = in.nextLine();
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        boolean[][][] fences = new boolean[1010][1010][2]; //2 for left fence and bottom fence
        int right = 0;
        int left = Integer.MAX_VALUE;
        int up = Integer.MAX_VALUE;
        int down = 0;

        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;
        Integer[] currPos = {505, 505};
        for (int i = 0; i < moveCount; i++) {
            char move = moves.charAt(i);
            right = Math.max(right, currPos[0]);
            left = Math.min(left, currPos[0]);
            up = Math.min(up, currPos[1]);
            down = Math.max(down, currPos[1]);
            switch (move) {
                case 'N': fences[currPos[0]][currPos[1]--][0] = true;
                north++;
                break;
                case 'S': fences[currPos[0]][++currPos[1]][0] = true;
                south++;
                break;
                case 'E': fences[currPos[0]++][currPos[1]][1] = true;
                east++;
                break;
                case 'W': fences[--currPos[0]][currPos[1]][1] = true;
                west++;
                break;
            }
        }
        left -= 2;
        right += 2;
        up -= 2;
        down += 2;
        if (north > 0 && south > 0 && east > 0 && west > 0) {
            int floodCounter = 0;
            boolean[][] flooded = new boolean[1010][1010];
            for (int i = left; i < right; i++) {
                for (int j = up; j < down; j++) {
                    if (flooded[i][j]) continue;
                    floodCounter++;
                    Integer[] temp = {i, j};
                    Queue<Integer[]> positions = new LinkedList<>();
                    positions.add(temp);
                    while (!positions.isEmpty()) {
                        currPos = positions.remove();
                        //System.out.println(currPos[0] + ", " + currPos[1]);
                        if (flooded[currPos[0]][currPos[1]]) continue;
                        flooded[currPos[0]][currPos[1]] = true;
                        for (int k = 0; k < 4; k++) {
                            temp = new Integer[2];
                            temp[0] = currPos[0] + dx[k];
                            temp[1] = currPos[1] + dy[k];
                            if (temp[0] < left || temp[0] >= right || temp[1] < up || temp[1] >= down) continue;
                            if (flooded[temp[0]][temp[1]]) continue;
                            if (k == 0) {
                                if (fences[temp[0]][temp[1]][0]) continue;
                            } else if (k == 1) {
                                if (fences[currPos[0]][currPos[1]][0]) continue;
                            } else if (k == 2) {
                                if (fences[currPos[0]][currPos[1]][1]) continue;
                            } else {
                                if (fences[temp[0]][temp[1]][1]) continue;
                            }
                            positions.add(temp);
                        }
                    }
                }
            }
            System.out.println(floodCounter - 1);
        } else {
            System.out.println(0); //did not go in all directions, no gates required
        }
    }
}
