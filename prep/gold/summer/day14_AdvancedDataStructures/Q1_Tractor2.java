package day14_AdvancedDataStructures;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q1_Tractor2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(in.readLine());
        int[] field = new int[len * len];
        for (int i = 0; i < len; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < len; j++) {
                field[len * i + j] = Integer.parseInt(st.nextToken());
            }
        }
        Edge[] edges = new Edge[(len * len * 4) - (4 * len)];
        int l = 0;
        for (int i = 0; i < len * len; i++) {
            if (i >= len) {
                edges[l] = new Edge(i, i - len, Math.abs(field[i] - field[i - len])); //up
                l++;
            }
            if (i % len != 0) {
                edges[l] = new Edge(i, i - 1, Math.abs(field[i] - field[i - 1])); //left
                l++;
            }
            if ((i + 1) % len != 0) {
                edges[l] = new Edge(i, i + 1, Math.abs(field[i] - field[i + 1])); //right
                l++;
            }
            if ((i + len) < len * len) {
                edges[l] = new Edge(i, i + len, Math.abs(field[i] - field[i + len])); //down
                l++;
            }
        }
        System.gc();
        Arrays.sort(edges);
        int maxDiff = 0;
        int size = 0;
        DisjointSet disjointSet = new DisjointSet(len * len);
        int index = 0;
        while (size < (len * len + 1) / 2) {
            int j = disjointSet.join(edges[index].endOne, edges[index].endTwo);
            if (j != -1) {
                size = j;
                maxDiff = Math.max(maxDiff, edges[index].cost);
            }
            index++;
        }
        System.out.println(maxDiff);
    }
    static class DisjointSet {
        int[] parents;
        int[] sizes;
        DisjointSet(int size) {
            parents = new int[size];
            sizes = new int[size];
            for (int i = 0; i < size; i++) parents[i] = i;
            for (int i = 0; i < size; i++) sizes[i] = 1;
        }
        boolean isConnected(int x1, int x2) { return getRoot(x1) == getRoot(x2);}
        private int getRoot(int x) {
            while (parents[x] != x) {
                parents[x] = parents[parents[x]];
                x = parents[x];
            }
            return parents[x];
        }
        int join(int x1, int x2) {
            if (isConnected(x1, x2)) return -1;
            int r1 = getRoot(x1);
            int r2 = getRoot(x2);
            if (sizes[r1] >= sizes[r2]) {
                parents[r2] = r1;
                sizes[r1] += sizes[r2];
            } else {
                parents[r1] = r2;
                sizes[r2] += sizes[r1];
            }
            return Math.max(sizes[r1], sizes[r2]);
        }
    }
    static class Edge implements Comparable<Edge> {
        int endOne;
        int endTwo;
        int cost;
        Edge(int one, int two, int cost) {
            endOne = one;
            endTwo = two;
            this.cost = cost;
        }
        public int compareTo(Edge a) {
            return this.cost - a.cost;
        }
    }
}
