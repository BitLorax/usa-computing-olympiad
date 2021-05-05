package day_15_Final;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q2_Roadblocks {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cheese = 3000; //bruh
        int intersectionCount = Integer.parseInt(st.nextToken());
        int roadCount = Integer.parseInt(st.nextToken());
        ArrayList<Connection>[] connections = new ArrayList[intersectionCount];
        for (int i = 0; i < intersectionCount; i++) connections[i] = new ArrayList<>();
        for (int i = 0; i < roadCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            connections[j].add(new Connection(c, k));
            connections[k].add(new Connection(c, j));
        }

        int[] fromStart = new int[intersectionCount];
        for (int i = 0; i < intersectionCount; i++) fromStart[i] = Integer.MAX_VALUE;
        boolean[] visited = new boolean[intersectionCount];

        PriorityQueue<Connection> possibilities = new PriorityQueue<>();
        possibilities.add(new Connection(0, 0));

        while (!possibilities.isEmpty()) {
            Connection currPos = possibilities.remove();
            if (visited[currPos.position]) continue;
            visited[currPos.position] = true;
            fromStart[currPos.position] = currPos.cost;
            for (Connection i : connections[currPos.position]) {
                possibilities.add(new Connection(currPos.cost + i.cost, i.position));
            }
        }
        int shortestPath = fromStart[intersectionCount - 1];
        int secondShortest = 1000000000;
        //int[] distances = new int[intersectionCount];
        int[] visitedCounter = new int[intersectionCount];
        //for (int i = 0; i < intersectionCount; i++) distances[i] = fromStart[i];
        possibilities = new PriorityQueue<>();
        possibilities.add(new Connection(0, 0));
        while (!possibilities.isEmpty()) {
            Connection currPos = possibilities.remove();
            visitedCounter[currPos.position]++;
            if (currPos.position == intersectionCount - 1 && currPos.cost > shortestPath && visitedCounter[currPos.position] == 2) {
                secondShortest = currPos.cost;
                break;
            }
            for (Connection i : connections[currPos.position]) {
                if (visitedCounter[i.position] >= 2) continue;
                if (currPos.cost + i.cost - fromStart[i.position] > cheese) continue;
                possibilities.add(new Connection(currPos.cost + i.cost, i.position));
            }
        }
        /*
        for (int i = 0; i < intersectionCount; i++) {
            if (fromStart[i] + fromEnd[i] > shortestPath && fromStart[i] + fromEnd[i] < secondShortest) secondShortest = fromStart[i] + fromEnd[i];
            if (connections[i].size() > 0) {
                Collections.sort(connections[i]);
                secondShortest = Math.min(secondShortest, fromStart[i] + fromEnd[i] + 2 * connections[i].get(0).cost);
            }
        }
        */
        System.out.println(secondShortest);
    }
    static class Connection implements Comparable<Connection>{
        int cost;
        int position;
        Connection(int c, int p) {
            cost = c;
            position = p;
        }
        public int compareTo(Connection a) {
            return this.cost - a.cost;
        }
    }
}
