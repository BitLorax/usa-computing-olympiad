package silver.usaco2016;

import java.io.*;
import java.util.*;

public class P3_WhyDidTheCowCrossTheRoadIII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/countcross.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/countcross.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int len = Integer.parseInt(st.nextToken());
        int cowCount = Integer.parseInt(st.nextToken());
        int roadCount = Integer.parseInt(st.nextToken());
        int[][] map = new int[len * 2 - 1][len * 2 - 1];
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int distantCows = 0;
        for (int i = 0; i < roadCount; i++) {
            st = new StringTokenizer(in.readLine());
            Coord first = new Coord(Integer.parseInt(st.nextToken()) * 2 - 2, Integer.parseInt(st.nextToken()) * 2 - 2);
            Coord second = new Coord(Integer.parseInt(st.nextToken()) * 2 - 2, Integer.parseInt(st.nextToken()) * 2 - 2);
            map[(first.x + second.x) / 2][(first.y + second.y) / 2] = 1;
        }
        ArrayList<Coord> cowPos = new ArrayList<>();
        for (int i = 0; i < cowCount; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken()) * 2 - 2;
            int y = Integer.parseInt(st.nextToken()) * 2 - 2;
            map[x][y] = 2;
            cowPos.add(new Coord(x, y));
        }
        for (int i = 0; i < cowCount; i++) {
            int cowsEncountered = 0;
            boolean[][] visited = new boolean[len * 2 - 1][len * 2 - 1];
            Queue<Coord> positions = new LinkedList<>();
            positions.add(new Coord(cowPos.get(i).x, cowPos.get(i).y));
            while (!positions.isEmpty()) {
                Coord currPos = positions.remove();
                if (currPos.x < 0 || currPos.x >= len * 2 - 1 || currPos.y < 0 || currPos.y >= len * 2 - 1) continue;
                if (visited[currPos.x][currPos.y]) continue;

                visited[currPos.x][currPos.y] = true;
                if (map[currPos.x][currPos.y] == 2) {
                    cowsEncountered++;
                }
                for (int j = 0; j < 4; j++) {
                    if (currPos.x + dx[j] * 2 < 0 || currPos.x + dx[j] * 2 >= len * 2 - 1 || currPos.y + dy[j] * 2 < 0 || currPos.y + dy[j] * 2 >= len * 2 - 1) continue;
                    if (map[currPos.x + dx[j]][currPos.y + dy[j]] == 1) continue;
                    positions.add(new Coord(currPos.x + dx[j] * 2, currPos.y + dy[j] * 2));
                }
            }
            distantCows += cowCount - cowsEncountered;
        }
        out.println(distantCows / 2);
        out.close();
    }
    static class Coord {
        int x;
        int y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
