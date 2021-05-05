package day13_BreadthFirstSearch;

import java.util.*;

public class Q5_CowBeautyPagentII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        char[][] map = new char[width][height];
        for (int i = 0; i < height; i++) {
            String row = in.nextLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
            }
        }
        ArrayList<Integer[]> spot1 = new ArrayList<>();
        ArrayList<Integer[]> spot2 = new ArrayList<>();
        boolean spot1Found = false;
        boolean[][] visited = new boolean[width][height];

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (visited[i][j] || map[i][j] == '.') continue;
                Queue<Integer[]> positions = new LinkedList<>();
                int size = 0;
                Integer[] temp = {i, j};
                positions.add(temp);
                while (!positions.isEmpty()) {
                    Integer[] currPos = positions.remove();
                    if (visited[currPos[0]][currPos[1]]) continue;
                    visited[currPos[0]][currPos[1]] = true;
                    if (!spot1Found) {
                        spot1.add(currPos);
                    } else {
                        spot2.add(currPos);
                    }
                    for (int k = 0; k < 4; k++) {
                        temp = new Integer[2];
                        temp[0] = currPos[0] + dx[k];
                        temp[1] = currPos[1] + dy[k];
                        if (temp[0] < 0 || temp[0] >= width || temp[1] < 0 || temp[1] >= height) continue;
                        if (map[temp[0]][temp[1]] == '.') continue;
                        if (visited[temp[0]][temp[1]]) continue;
                        positions.add(temp);
                    }
                }
                if (!spot1Found) {
                    spot1Found = true;
                }
            }
        }
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i < spot1.size(); i++) {
            for (int j = 0; j < spot2.size(); j++) {
                int diff = Math.abs(spot1.get(i)[0] - spot2.get(j)[0]) + Math.abs(spot1.get(i)[1] - spot2.get(j)[1]) - 1;
                minDiff = Math.min(minDiff, diff);
            }
        }
        System.out.println(minDiff);
    }
}
