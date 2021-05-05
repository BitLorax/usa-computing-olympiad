package day11_Graphs;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q7_DistantPastures {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int len = Integer.parseInt(st.nextToken());
        int sameTime = Integer.parseInt(st.nextToken());
        int diffTime = Integer.parseInt(st.nextToken());
        boolean[][] pasture = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            String row = in.readLine();
            for (int j = 0; j < len; j++) {
                if (row.charAt(j) == '(') pasture[j][i] = true;
            }
        }
        ArrayList<Connection>[] connections = new ArrayList[len * len];
        for (int i = 0; i < len * len; i++) connections[i] = new ArrayList<>();
        for (int i = 0; i < len; i++) { //x
            for (int j = 0; j < len; j++) { //y
                int k = j * len + i;
                if (i > 0) connections[k].add(new Connection((pasture[i][j] == pasture[i - 1][j]) ? sameTime : diffTime, k - 1));
                if (i < len - 1) connections[k].add(new Connection((pasture[i][j] == pasture[i + 1][j]) ? sameTime : diffTime, k + 1));
                if (j > 0) connections[k].add(new Connection((pasture[i][j] == pasture[i][j - 1]) ? sameTime : diffTime, k - len));
                if (j < len - 1) connections[k].add(new Connection((pasture[i][j] == pasture[i][j + 1]) ? sameTime : diffTime, k + len));
            }
        }
        int max = 0;
        for (int ii = 0; ii < len * len; ii++) {
            PriorityQueue<Connection> possibilities = new PriorityQueue<>();
            possibilities.add(new Connection(0, ii));
            boolean[] visited = new boolean[len * len];
            while (!possibilities.isEmpty()) {
                Connection currNode = possibilities.remove();
                if (visited[currNode.position]) continue;
                visited[currNode.position] = true;
                max = Math.max(max, currNode.cost);
                for (Connection i : connections[currNode.position]) {
                    possibilities.add(new Connection(i.cost + currNode.cost, i.position));
                }
            }
        }
        System.out.println(max);
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
