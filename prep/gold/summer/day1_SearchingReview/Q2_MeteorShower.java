package day1_SearchingReview;

import java.io.*;
import java.util.*;

public class Q2_MeteorShower {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int meteorCount = Integer.parseInt(in.readLine());

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        Map<Integer, ArrayList<Coord>> meteors = new TreeMap<>();
        for (int i = 0; i < meteorCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());
            if (!meteors.containsKey(time)) {
                meteors.put(time, new ArrayList<>());
            }
            meteors.get(time).add(new Coord(x, y, -1));
        }

        boolean[][] pasture = new boolean[310][310];
        ArrayList<Coord> startPos = new ArrayList<>();
        Coord currPos = new Coord(0, 0, 0);
        startPos.add(currPos);

        for (int time : meteors.keySet()) {
            boolean[][] visited = new boolean[310][310];
            Queue<Coord> positions = new LinkedList<>();
            positions.addAll(startPos);
            startPos = new ArrayList<>();
            while (!positions.isEmpty()) {
                currPos = positions.remove();
                if (currPos.x < 0 || currPos.x >= 310 || currPos.y < 0 || currPos.y >= 310) continue;
                if (visited[currPos.x][currPos.y]) continue;
                if (currPos.time > time) continue;
                visited[currPos.x][currPos.y] = true;
                if (!pasture[currPos.x][currPos.y]) {
                    startPos.add(currPos);
                    if (time == ((TreeMap<Integer, ArrayList<Coord>>) meteors).lastKey());
                } else {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    Coord newPos = new Coord(currPos.x + dx[i], currPos.y + dy[i], currPos.time + 1);
                    if (newPos.x < 0 || newPos.x >= 310 || newPos.y < 0 || newPos.y >= 310) continue;
                    positions.add(newPos);
                }
            }
            for (int j = 0; j < meteors.get(time).size(); j++) {
                int x = meteors.get(time).get(j).x;
                int y = meteors.get(time).get(j).y;
                pasture[x][y] = true;
                for (int i = 0; i < 4; i++) {
                    int tempX = x + dx[i];
                    int tempY = y + dy[i];
                    if (tempX < 0 || tempX >= 310 || tempY < 0 || tempY >= 310) continue;
                    pasture[tempX][tempY] = true;
                }
            }
        }
        boolean alive = false;
        for (Coord i : startPos) {
            if (!pasture[i.x][i.y]) {
                System.out.println(i.time);
                alive = true;
                break;
            }
        }
        if (!alive) System.out.println("-1");
    }
    static class Coord {
        int x;
        int y;
        int time;
        Coord (int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }

    }
}
