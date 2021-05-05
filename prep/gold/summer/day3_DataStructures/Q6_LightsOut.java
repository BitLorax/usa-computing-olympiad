package day3_DataStructures;

import java.io.*;
import java.util.StringTokenizer;

public class Q6_LightsOut {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int vertexCount = Integer.parseInt(in.readLine());
        Coord[] vertexInfo = new Coord[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            vertexInfo[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        int[] distances = new int[vertexCount]; //distance to vertex i from previous pos, clockwise
        int sum = 0;
        int[] distanceFromExitCounter = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            int k = i - 1;
            if (k < 0) k += vertexCount;
            distances[i] = Math.abs(vertexInfo[i].x - vertexInfo[k].x + vertexInfo[i].y - vertexInfo[k].y);

            if (i != 0) sum += Math.abs(vertexInfo[i].x - vertexInfo[k].x + vertexInfo[i].y - vertexInfo[k].y);
            distanceFromExitCounter[i] = sum;
        }
        sum = 0;
        int[] distanceFromExitClock = new int[vertexCount];
        for (int i = vertexCount - 1; i >= 0; i--) {
            int k = i + 1;
            if (k == vertexCount) k = 0;
            sum += Math.abs(vertexInfo[i].x - vertexInfo[k].x + vertexInfo[i].y - vertexInfo[k].y);
            distanceFromExitClock[i] = sum;
        }
        distanceFromExitClock[0] = 0;
        int[] closestDistFromExit = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            closestDistFromExit[i] = Math.min(distanceFromExitClock[i], distanceFromExitCounter[i]);
        }
        boolean[] turnRight = new boolean[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            int j = i - 1;
            if (j < 0) j += vertexCount;
            int diffX1 = vertexInfo[(i) % vertexCount].x - vertexInfo[(j) % vertexCount].x;
            int diffX2 = vertexInfo[(i + 1) % vertexCount].x - vertexInfo[(i) % vertexCount].x;
            int diffY1 = vertexInfo[(i) % vertexCount].y - vertexInfo[(j) % vertexCount].y;
            int diffY2 = vertexInfo[(i + 1) % vertexCount].y - vertexInfo[(i) % vertexCount].y;
            turnRight[i] = ((diffY1 > 0 && diffX2 > 0) || (diffX1 > 0 && diffY2 < 0) || (diffY1 < 0 && diffX2 < 0) || (diffX1 < 0 && diffY2 > 0));
        }

        int maxDiff = 0;
        for (int i = 1; i < vertexCount; i++) { //start at every vertex
            boolean[] different = new boolean[vertexCount];
            int sidesPassed = 0;
            int differentCount = 1;
            int distanceWalked = 0;
            while (differentCount < vertexCount - 1) {
                if ((i + sidesPassed) % vertexCount == 0) break; //reached exit
                for (int j = 1; j < vertexCount; j++) {
                    if (j == i) continue;
                    if (different[j]) continue;
                    if (sidesPassed > 0 && distances[(j + sidesPassed) % vertexCount] != distances[(i + sidesPassed) % vertexCount]) { //distance not the same
                        different[j] = true;
                        differentCount++;
                        continue;
                    }
                    if (turnRight[(j + sidesPassed) % vertexCount] != turnRight[(i + sidesPassed) % vertexCount]) { //turned differently
                        different[j] = true;
                        differentCount++;
                        continue;
                    }
                    if ((j + sidesPassed) % vertexCount == 0) { //would've reached exit already
                        different[j] = true;
                        differentCount++;
                    }
                }
                sidesPassed++;
                distanceWalked += distances[(i + sidesPassed) % vertexCount];
            }
            distanceWalked -= distances[(i + sidesPassed) % vertexCount];
            sidesPassed--;
            //if (maxDiff < distanceWalked + closestDistFromExit[(i + sidesPassed) % vertexCount] - closestDistFromExit[i]) System.out.println(maxDiff);
            maxDiff = Math.max(maxDiff, distanceWalked + closestDistFromExit[(i + sidesPassed) % vertexCount] - closestDistFromExit[i]);
        }
        System.out.println(maxDiff);
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
