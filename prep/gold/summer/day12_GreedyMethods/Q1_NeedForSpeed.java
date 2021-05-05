package day12_GreedyMethods;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q1_NeedForSpeed {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int force = Integer.parseInt(st.nextToken());
        int mass = Integer.parseInt(st.nextToken());
        int partCount = Integer.parseInt(st.nextToken());
        Part[] partInfo = new Part[partCount];
        for (int i = 0; i < partCount; i++) {
            st = new StringTokenizer(in.readLine());
            partInfo[i] = new Part(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), i + 1);
        }
        Arrays.sort(partInfo);
        ArrayList<Integer> partsChosen = new ArrayList<>();
        for (int i = 0; i < partCount; i++) {
            if (partInfo[i].ratio > ((double)force / mass)) {
                partsChosen.add(partInfo[i].id);
                force += partInfo[i].f;
                mass += partInfo[i].m;
            } else {
                break;
            }
        }
        Collections.sort(partsChosen);
        if (partsChosen.size() > 0) for (int i : partsChosen) System.out.println(i);
        else System.out.println("NONE");
    }
    static class Part implements Comparable<Part>{
        int f;
        int m;
        double ratio;
        int id;
        Part(int f, int m, int id) {
            this.f = f;
            this.m = m;
            this.id = id;
            ratio = (double)f / m;
        }
        public int compareTo(Part a) {
            return (int)(a.ratio - this.ratio);
        }
    }
}
