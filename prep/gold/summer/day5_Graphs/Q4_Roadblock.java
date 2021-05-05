package day5_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q4_Roadblock {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int farmCount = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        int[][] connections = new int[farmCount][farmCount];
        for (int i = 0; i < farmCount; i++) {
            for (int j = 0; j < farmCount; j++) {
                connections[i][j] = 1000000000;
            }
        }
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int l = Integer.parseInt(st.nextToken());
            connections[j][k] = l;
            connections[k][j] = l;
        }
        int[] minDist = new int[farmCount];
        for (int i = 1; i < farmCount; i++) {
            minDist[i] = 1000000000;
        }
        boolean[] visited = new boolean[farmCount];
        ArrayList<Integer>[] pathTaken = new ArrayList[farmCount];
        for (int i = 0; i < farmCount; i++) {
            pathTaken[i] = new ArrayList<>();
        }
        for (int i = 0; i < farmCount; i++) {
            int closestFarm = -1;
            int closestDist = 1000000001;
            for (int j = 0; j < farmCount; j++) {
                if (!visited[j] && minDist[j] < closestDist) {
                    closestDist = minDist[j];
                    closestFarm = j;
                }
            }
            visited[closestFarm] = true;
            for (int j = 0; j < farmCount; j++) {
                if (minDist[j] > minDist[closestFarm] + connections[closestFarm][j]) {
                    minDist[j] = minDist[closestFarm] + connections[closestFarm][j];
                    pathTaken[j] = (ArrayList<Integer>)pathTaken[closestFarm].clone();
                    pathTaken[j].add(closestFarm);
                }
            }
        }
        int withoutBlock = minDist[farmCount - 1];
        pathTaken[farmCount - 1].add(farmCount - 1);
        int maxDist = 0;
        for (int i = 0; i < pathTaken[farmCount - 1].size() - 1; i++) {
            connections[pathTaken[farmCount - 1].get(i)][pathTaken[farmCount - 1].get(i + 1)] *= 2;
            connections[pathTaken[farmCount - 1].get(i + 1)][pathTaken[farmCount - 1].get(i)] *= 2;
            visited = new boolean[farmCount];
            minDist = new int[farmCount];
            for (int j = 1; j < farmCount; j++) {
                minDist[j] = 1000000000;
            }
            for (int j = 0; j < farmCount; j++) {
                int closestFarm = -1;
                int closestDist = 1000000001;
                for (int k = 0; k < farmCount; k++) {
                    if (!visited[k] && minDist[k] < closestDist) {
                        closestDist = minDist[k];
                        closestFarm = k;
                    }
                }
                visited[closestFarm] = true;
                for (int k = 0; k < farmCount; k++) {
                    minDist[k] = Math.min(minDist[k], minDist[closestFarm] + connections[closestFarm][k]);
                }
            }
            maxDist = Math.max(maxDist, minDist[farmCount - 1]);
            connections[pathTaken[farmCount - 1].get(i)][pathTaken[farmCount - 1].get(i + 1)] /= 2;
            connections[pathTaken[farmCount - 1].get(i + 1)][pathTaken[farmCount - 1].get(i)] /= 2;
        }
        System.out.println(maxDist - withoutBlock);
    }
}
