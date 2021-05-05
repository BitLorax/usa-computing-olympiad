package day11_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q5_DijkstrasShortestPathII {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int vertexCount = Integer.parseInt(st.nextToken());
        int edgeCount = Integer.parseInt(st.nextToken());
        int source = Integer.parseInt(st.nextToken()) - 1;
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
        int[] distances = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++) distances[i] = -1;
        PriorityQueue<Connection> possibilities = new PriorityQueue<>();
        possibilities.add(new Connection(0, source));
        boolean[] visited = new boolean[vertexCount];
        while (!possibilities.isEmpty()) {
            Connection currNode = possibilities.remove();
            if (visited[currNode.position]) continue;
            visited[currNode.position] = true;
            distances[currNode.position] = currNode.cost;
            for (Connection i : connections[currNode.position]) {
                possibilities.add(new Connection(i.cost + currNode.cost, i.position));
            }
        }
        for (int i = 0; i < vertexCount; i++) {
            if (i == source) System.out.println(0);
            else System.out.println(distances[i]);
        }
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
