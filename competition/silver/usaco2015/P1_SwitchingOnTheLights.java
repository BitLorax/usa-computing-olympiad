package silver.usaco2015;

import java.io.*;
import java.util.*;

public class P1_SwitchingOnTheLights {
    private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2015/lightson.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2015/lightson.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int roomLen = Integer.parseInt(st.nextToken());
        int switchCount = Integer.parseInt(st.nextToken());
        boolean[][] lights = new boolean[roomLen][roomLen];
        boolean[][] visited = new boolean[roomLen][roomLen];

        Map<Integer, ArrayList<Coord>> switches = new HashMap<>();
        for (int i = 0; i < switchCount; i++) {
            st = new StringTokenizer(in.readLine());
            Coord first = new Coord(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
            Coord second = new Coord(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
            int firstHash = hash(first);
            if (!switches.containsKey(firstHash)) {
                switches.put(firstHash, new ArrayList<>());
            }
            switches.get(firstHash).add(second);
        }

        int lightsOn = 1;
        lights[0][0] = true;

        Queue<Coord> positions = new LinkedList<>();
        positions.add(new Coord(0, 0));
        while (!positions.isEmpty()) {
            Coord currPos = positions.remove();
            if (currPos.x < 0 || currPos.x >= roomLen || currPos.y < 0 || currPos.y >= roomLen) continue;
            if (visited[currPos.x][currPos.y]) continue;
            visited[currPos.x][currPos.y] = true;
            ArrayList<Coord> targets = switches.get(hash(currPos));
            if (targets != null) {
                for (Coord pos : targets) {
                    if (!lights[pos.x][pos.y]) {
                        lightsOn++;
                        if (nextToVisited(pos, visited)) positions.add(new Coord(pos.x, pos.y));
                    }
                    lights[pos.x][pos.y] = true;
                }
            }
            for (int i = 0; i < 4; i++) {
                Coord newPos = new Coord(currPos.x + dx[i], currPos.y + dy[i]);
                if (newPos.x < 0 || newPos.x >= roomLen || newPos.y < 0 || newPos.y >= roomLen) continue;
                if (visited[newPos.x][newPos.y]) continue;
                if (!lights[newPos.x][newPos.y]) continue;
                positions.add(newPos);
            }
        }
        out.println(lightsOn);
        out.close();
    }
    private static int hash(Coord in) {
        return in.x * 1000000 + in.y;
    }
    private static boolean nextToVisited(Coord pos, boolean[][] visited) {
        for (int i = 0; i < 4; i++) {
            Coord testPos = new Coord(pos.x + dx[i], pos.y + dy[i]);
            if (testPos.x < 0 || testPos.x >= visited.length || testPos.y < 0 || testPos.y >= visited.length) continue;
            if (visited[testPos.x][testPos.y]) {
                return true;
            }
        }
        return false;
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
