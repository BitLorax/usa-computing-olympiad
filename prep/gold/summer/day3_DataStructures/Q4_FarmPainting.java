package day3_DataStructures;

import java.io.*;
import java.util.*;

public class Q4_FarmPainting {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int enclosureCount = Integer.parseInt(in.readLine());
        Wall[] walls = new Wall[enclosureCount * 2];

        Map<Wall, Wall> wallPairs = new HashMap<>();
        for (int i = 0; i < enclosureCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            Wall wall1 = new Wall(Math.max(y1, y2), Math.min(y1, y2), Math.min(x1, x2), true);
            Wall wall2 = new Wall(Math.max(y1, y2), Math.min(y1, y2), Math.max(x1, x2), false);
            walls[i * 2] = wall1;
            walls[i * 2 + 1] = wall2;
            wallPairs.put(wall2, wall1);
        }
        Arrays.sort(walls);
        ArrayList<Wall> uncontained = new ArrayList<>();
        for (int i = 0; i < walls.length; i++) {
            Wall currWall = walls[i];
            if (!currWall.start) {
                uncontained.remove(wallPairs.get(currWall));
            } else {
                boolean contained = false;
                for (Wall j : uncontained) {
                    if (currWall.topY < j.topY && currWall.bottomY > j.bottomY) {
                        contained = true;
                        break;
                    }
                }
                if (!contained) uncontained.add(currWall);
                else currWall.contained = true;
            }
        }
        int uncontainedEnclosures = 0;
        for (Wall i : walls) {
            if (!i.contained && i.start) uncontainedEnclosures++;
        }
        System.out.println(uncontainedEnclosures);
    }
    static class Wall implements Comparable<Wall> {
        int topY;
        int bottomY;
        int x;
        boolean start;
        boolean contained;
        Wall (int ty, int by, int x, boolean start) {
            this.topY = ty;
            this.bottomY = by;
            this.x = x;
            this.start = start;
            contained = false;
        }
        public int compareTo (Wall a) {
            return this.x - a.x;
        }
    }
}
