package day12_BreadthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q4_CornMaze {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());

        int[][] map = new int[width][height];
        Coord currPos = new Coord(0, 0);
        Map<Character, Integer> teleLocations = new HashMap<>(); //to store teleporters when its pair has not been found
        Map<Integer, Integer> telePairs = new HashMap<>(); //stores pairs of teleporters, if there is no pair, it woun't show up in here
        for (int i = 0; i < height; i++) {
            String row = in.readLine();
            for (int j = 0; j < width; j++) {
                map[j][i] = row.charAt(j);
                if (Character.isLetter(row.charAt(j))) {
                    if (teleLocations.containsKey(row.charAt(j))) {
                        Coord temp = new Coord(j, i);
                        telePairs.put(hash(temp), teleLocations.get(row.charAt(j)));
                        telePairs.put(teleLocations.get(row.charAt(j)), hash(temp));
                    } else {
                        Coord temp = new Coord(j, i);
                        teleLocations.put(row.charAt(j), hash(temp));
                    }
                } else if (row.charAt(j) == '@') {
                    currPos = new Coord(j, i);
                }
            }
        }
        
        Queue<Coord> positions = new LinkedList<>();
        positions.add(currPos);
        boolean[][] visited = new boolean[width][height];
        int[][] portalVisits = new int[width][height];
        int shortestPath = Integer.MAX_VALUE;
        while (!positions.isEmpty()) {
            currPos = positions.remove();
            if (visited[currPos.x][currPos.y] && !Character.isLetter(map[currPos.x][currPos.y])) continue;
            visited[currPos.x][currPos.y] = true;
            if (map[currPos.x][currPos.y] == '=') {
                shortestPath = Math.min(currPos.pathLen, shortestPath);
                break;
            } //check if complete
            if (!(!currPos.fromTele && Character.isLetter(map[currPos.x][currPos.y]))) {
                for (int i = 0; i < 4; i++) {
                    Coord temp = new Coord(currPos.x + dx[i], currPos.y + dy[i], currPos.pathLen + 1);

                    if (temp.x < 0 || temp.x >= map.length || temp.y < 0 || temp.y >= map[0].length) continue;
                    if (visited[temp.x][temp.y] && !Character.isLetter(map[temp.x][temp.y])) continue;
                    if (map[temp.x][temp.y] == '#') {
                        continue;
                    } //check if the cow is walking into something that's not a path or teleporter
                    if (Character.isLetter(map[temp.x][temp.y]) && telePairs.containsKey(hash(temp))) {
                        Coord pair = undoHash(telePairs.get(hash(temp)));
                        pair.pathLen = temp.pathLen; //transfer path length
                        if (portalVisits[temp.x][temp.y] < 2 || portalVisits[pair.x][pair.y] < 2) {
                            if (!temp.fromTele) {
                                pair.fromTele = true;
                                positions.add(pair);
                                portalVisits[temp.x][temp.y]++;
                            }
                        }
                    }
                    temp.fromTele = false;
                    positions.add(temp);
                }
            }
        }
        System.out.println(shortestPath);
    }
    static class Coord {
        int x;
        int y;
        int pathLen;
        boolean fromTele;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
            this.pathLen = 0;
            this.fromTele = false;
        }
        Coord (int x, int y, int pathLen) {
            this.x = x;
            this.y = y;
            this.pathLen = pathLen;
            this.fromTele = false;
        }
    }
    private static int hash(Coord coord) {
        return coord.x * 1000000 + coord.y;
    }
    private static Coord undoHash(int in) {
        return new Coord((in - (in % 1000000)) / 1000000, in % 1000000);
    }

}
