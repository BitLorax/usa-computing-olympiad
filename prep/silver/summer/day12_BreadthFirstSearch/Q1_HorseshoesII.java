package day12_BreadthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q1_HorseshoesII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int size = Integer.parseInt(in.nextLine());
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int maxHorseShoes = 0;
        int[][] map = new int[size][size];
        for (int i = 0; i < size; i++) {
            String line = in.nextLine();
            for (int j = 0; j < size; j++) {
                if (line.substring(j, j + 1).equals("(")) {
                    map[j][i] = 1;
                } else {
                    map[j][i] = -1;
                }
            }
        }

        //each coord: x, y, sum, horseshoes, switched (0 = false, 1 = true)
        //seperate queue for visited

        Queue<Integer[]> positions = new LinkedList<>();
        Queue<boolean[][]> visitedQueue = new LinkedList<>();
        Integer[] newPos = {0, 0, 0, 0, 0};
        newPos[2] += map[newPos[0]][newPos[1]];
        newPos[3]++;
        if (map[newPos[0]][newPos[1]] == -1) newPos[4] = 1; //switched to ), cannot put more ('s
        positions.add(newPos);
        visitedQueue.add(new boolean[map.length][map[0].length]);

        while (!positions.isEmpty()) {
            Integer[] currPos = positions.remove();
            boolean[][] visited = visitedQueue.remove();
            
            if (visited[currPos[0]][currPos[1]]) continue;
            boolean[][] newVisited = new boolean[visited.length][visited[0].length];
            for (int i = 0; i < visited.length; i++) {
                for (int j = 0; j < visited[i].length; j++) {
                    newVisited[i][j] = visited[i][j];
                }
            }
            newVisited[currPos[0]][currPos[1]] = true;
            
            if (currPos[2] == 0 && currPos[4] == 1) {
                maxHorseShoes = Math.max(maxHorseShoes, currPos[3]);
                continue;
            }
            for (int i = 0; i < 4; i++) {
                newPos = new Integer[5];
                newPos[0] = currPos[0] + dx[i];
                newPos[1] = currPos[1] + dy[i];
                newPos[2] = currPos[2];
                newPos[3] = currPos[3];
                newPos[4] = currPos[4];
                
                if (newPos[0] < 0 || newPos[0] >= size || newPos[1] < 0 || newPos[1] >= size) continue;
                if (newVisited[newPos[0]][newPos[1]]) continue;

                newPos[2] += map[newPos[0]][newPos[1]];

                if (map[newPos[0]][newPos[1]] == 1 && newPos[4] == 1) continue; //can't put in a ( after )
                if (map[newPos[0]][newPos[1]] == -1) newPos[4] = 1; //switched to ), cannot put more ('s
                if (newPos[2] < 0) continue; //out of balance, can't get balanced
                newPos[3]++;
                positions.add(newPos);
                visitedQueue.add(newVisited);
            }
        }
        System.out.println(maxHorseShoes);
    }
}
