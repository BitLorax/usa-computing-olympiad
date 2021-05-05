package day11_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q6_PackageDelivery {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int barnCount = Integer.parseInt(st.nextToken());
        int pathCount = Integer.parseInt(st.nextToken());
        ArrayList<Connection>[] connections = new ArrayList[barnCount];
        for (int i = 0; i < barnCount; i++) connections[i] = new ArrayList<>();
        for (int i = 0; i < pathCount; i++) {
            st = new StringTokenizer(in.readLine());
            int j = Integer.parseInt(st.nextToken()) - 1;
            int k = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            connections[j].add(new Connection(c, k));
            connections[k].add(new Connection(c, j));
        }
        int minDist = -1;
        PriorityQueue<Connection> possibilities = new PriorityQueue<>();
        possibilities.add(new Connection(0, 0));
        boolean[] visited = new boolean[barnCount];
        while (!possibilities.isEmpty()) {
            Connection currNode = possibilities.remove();
            if (visited[currNode.position]) continue;
            visited[currNode.position] = true;
            if (currNode.position == barnCount - 1) minDist = currNode.cost;
            for (Connection i : connections[currNode.position]) possibilities.add(new Connection(i.cost + currNode.cost, i.position));
        }
        System.out.println(minDist);
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
