package day14_AdvancedDataStructures;

import java.io.*;
import java.util.StringTokenizer;

public class Q2_Moocast {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Coord[] cowLocs = new Coord[cowCount];
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            cowLocs[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        int dist = 0;
        int[] distances = new int[cowCount];
        boolean[] visited = new boolean[cowCount];
        for (int i = 1; i < cowCount; i++) distances[i] = 1000000001;
        for (int ii = 0; ii < cowCount; ii++) {
            int closestCow = -1;
            int closestDist = 1000000000;
            for (int i = 0; i < cowCount; i++) {
                if (distances[i] < closestDist && !visited[i]) {
                    closestCow = i;
                    closestDist = distances[i];
                }
            }
            dist = Math.max(dist, closestDist);
            visited[closestCow] = true;
            for (int i = 0; i < cowCount; i++) {
                if (i == closestCow) continue;
                if (visited[i]) continue;
                int j = cowLocs[closestCow].getDist(cowLocs[i]);
                distances[i] = Math.min(distances[i], j);
            }
        }
        System.out.println(dist);
    }
    static class Coord {
        int x;
        int y;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
        int hash() { return this.x * 1000000000 + this.y;}
        int getDist(Coord a) {
            return Math.abs((this.x - a.x) * (this.x - a.x)) + Math.abs((this.y - a.y) * (this.y - a.y));
        }
    }
}
