package day11_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q2_MinimumSpanningTreeII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int vertexCount = Integer.parseInt(st.nextToken());
        int edgeCount = Integer.parseInt(st.nextToken());
        ArrayList<Connection>[] connections = new ArrayList[vertexCount];
        for (int i = 0; i < vertexCount; i++) connections[i] = new ArrayList<>();
        for (int i = 0; i < edgeCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            connections[j].add(new Connection(c, k));
            connections[k].add(new Connection(c, j));
        }
        Collections.sort(connections[0]);
        int totalCost = 0;
        boolean[] visited = new boolean[vertexCount];
        visited[0] = true;
        PriorityQueue<Connection> currDists = new PriorityQueue<>();
        for (Connection i : connections[0]) currDists.add(i);
        while (!currDists.isEmpty()) {
            Connection currVertex = currDists.remove();
            if (visited[currVertex.position]) continue;
            visited[currVertex.position] = true;
            totalCost += currVertex.cost;
            for (Connection i : connections[currVertex.position]) currDists.add(i);
        }
        System.out.println(totalCost);
    }
    static class Connection implements Comparable<Connection>{
        int cost;
        int position;
        Connection(int c, int d) {
            cost = c;
            position = d;
        }
        public int compareTo(Connection a) {
            return this.cost - a.cost;
        }
    }
}
