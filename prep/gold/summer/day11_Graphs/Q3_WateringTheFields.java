package day11_Graphs;

import java.io.*;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q3_WateringTheFields {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int fieldCount = Integer.parseInt(st.nextToken());
        int minCost = Integer.parseInt(st.nextToken());
        Coord[] fieldPositions = new Coord[fieldCount];
        for (int i = 0; i < fieldCount; i++) {
            st = new StringTokenizer(in.readLine());
            fieldPositions[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        boolean[] visited = new boolean[fieldCount];
        int sum = 0;
        int[] distances = new int[fieldCount];
        for (int i = 1; i < fieldCount; i++) distances[i] = 10000001;
        for (int ii = 0; ii < fieldCount; ii++) {
            int closestDist = 10000000;
            int closestVertex = -1;
            for (int i = 0; i < fieldCount; i++) {
                if (!visited[i] && distances[i] < closestDist) {
                    closestDist = distances[i];
                    closestVertex = i;
                }
            }
            if (closestVertex == -1) {
                sum = -1;
                break;
            }
            visited[closestVertex] = true;
            sum += distances[closestVertex];
            for (int i = 0; i < fieldCount; i++) {
                int j = getDist(fieldPositions[closestVertex], fieldPositions[i]);
                if (j >= minCost) {
                    distances[i] = Math.min(distances[i], j);
                }
            }
        }
        System.out.println(sum);
    }
    private static int getDist(Coord a, Coord b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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
