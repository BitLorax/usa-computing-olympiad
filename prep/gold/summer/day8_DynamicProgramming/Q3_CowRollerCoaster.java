package day8_DynamicProgramming;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q3_CowRollerCoaster {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int landLen = Integer.parseInt(st.nextToken());
        int componentCount = Integer.parseInt(st.nextToken());
        int budget = Integer.parseInt(st.nextToken());
        Component[] componentInfo = new Component[componentCount];
        for (int i = 0; i < componentCount; i++) {
            st = new StringTokenizer(in.readLine());
            componentInfo[i] = new Component(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(componentInfo);
        int[][] states = new int[landLen + 1][budget + 1];
        for (int i = 0; i <= landLen; i++) for (int j = 0; j <= budget; j++) states[i][j] = -1;
        states[0][0] = 0;
        for (int i = 0; i < componentCount; i++) {
            for (int j = budget; j >= componentInfo[i].cost; j--) {
                if (states[componentInfo[i].startPos][j - componentInfo[i].cost] != -1) {
                    states[componentInfo[i].endPos][j] = Math.max(states[componentInfo[i].endPos][j], states[componentInfo[i].startPos][j - componentInfo[i].cost] + componentInfo[i].fun);
                }
            }
        }
        int max = -1;
        for (int i : states[landLen]) max = Math.max(max, i);
        System.out.println(max);
    }
    static class Component implements Comparable<Component> {
        int startPos;
        int endPos;
        int fun;
        int cost;
        Component(int s, int w, int f, int c) {
            startPos = s;
            endPos = s + w;
            fun = f;
            cost = c;
        }
        public int compareTo(Component a) {
            return this.startPos - a.startPos;
        }
    }
}
