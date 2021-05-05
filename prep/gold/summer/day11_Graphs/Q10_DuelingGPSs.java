package day11_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q10_DuelingGPSs {
    private static int intersectionCount;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        intersectionCount = Integer.parseInt(st.nextToken());
        int roadCount = Integer.parseInt(st.nextToken());
        ArrayList<Connection>[] gpsOne = new ArrayList[intersectionCount];
        ArrayList<Connection>[] gpsTwo = new ArrayList[intersectionCount];
        for (int i = 0; i < intersectionCount; i++) {
            gpsOne[i] = new ArrayList<>();
            gpsTwo[i] = new ArrayList<>();
        }
        for (int i = 0; i < roadCount; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int p = Integer.parseInt(st.nextToken()) ;
            int q = Integer.parseInt(st.nextToken());
            gpsOne[b].add(new Connection(a, p));
            gpsTwo[b].add(new Connection(a, q));
        }
        int[][] distances = new int[3][intersectionCount];
        distances[0] = dijkstras(gpsOne, intersectionCount - 1);
        distances[1] = dijkstras(gpsTwo, intersectionCount - 1);

        ArrayList<Connection>[] complaints = new ArrayList[intersectionCount];
        for (int i = 0; i < intersectionCount; i++) complaints[i] = new ArrayList<>();
        for (int i = 0; i < intersectionCount; i++) {
            for (int j = 0; j < gpsOne[i].size(); j++) {
                int nextPos = gpsOne[i].get(j).position;
                int k = 0;
                int distanceOne = gpsOne[i].get(j).cost;
                int distanceTwo = gpsTwo[i].get(j).cost;
                if (distances[0][nextPos] - distances[0][i] != distanceOne) k++;
                if (distances[1][nextPos] - distances[1][i] != distanceTwo) k++;
                complaints[nextPos].add(new Connection(i, k));
            }
        }
        System.out.println(dijkstras(complaints, 0)[intersectionCount - 1]);
    }
    private static int[] dijkstras(ArrayList<Connection>[] connections, int start) {
        int[] distances = new int[intersectionCount];
        for (int i = 0; i < intersectionCount; i++) distances[i] = Integer.MAX_VALUE;
        boolean[] visited = new boolean[intersectionCount];

        PriorityQueue<Connection> possibilities = new PriorityQueue<>();
        possibilities.add(new Connection(start, 0));

        while (!possibilities.isEmpty()) {
            Connection currPos = possibilities.remove();
            if (visited[currPos.position]) continue;
            visited[currPos.position] = true;
            distances[currPos.position] = currPos.cost;
            for (Connection i : connections[currPos.position]) {
                possibilities.add(new Connection(i.position, currPos.cost + i.cost));
            }
        }
        return distances;
    }
    static class Connection implements Comparable<Connection>{
        int position;
        int cost;
        Connection(int p, int c) {
            position = p;
            cost = c;
        }
        public int compareTo(Connection a) {
            return this.cost - a.cost;
        }
    }
}