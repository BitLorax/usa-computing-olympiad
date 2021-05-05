package day11_Graphs;

import java.io.*;
import java.util.*;


@SuppressWarnings("unchecked")
public class Q1_CowPicnic {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int pastureCount = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        int[] cowLocs = new int[cowCount];
        for (int i = 0; i < cowCount; i++) cowLocs[i] = Integer.parseInt(in.readLine()) - 1;
        ArrayList<Integer>[] connections = new ArrayList[pastureCount];
        for (int i = 0; i < pastureCount; i++) connections[i] = new ArrayList<>();
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            connections[Integer.parseInt(st.nextToken()) - 1].add(Integer.parseInt(st.nextToken()) - 1);
        }
        boolean[][] visited = new boolean[pastureCount][cowCount];
        for (int i = 0; i < cowCount; i++) {
            Queue<Integer> possibleLocations = new LinkedList<>();
            possibleLocations.add(cowLocs[i]);
            while (!possibleLocations.isEmpty()) {
                int cow = possibleLocations.remove();
                if (visited[cow][i]) continue;
                visited[cow][i] = true;
                for (int j : connections[cow]) {
                    possibleLocations.add(j);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < pastureCount; i++) {
            boolean valid = true;
            for (boolean j : visited[i]) if (!j) valid = false;
            if (valid) sum++;
        }
        System.out.println(sum);
    }
}
