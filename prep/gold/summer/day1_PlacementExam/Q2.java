package placement;

import java.io.*;
import java.util.*;

public class Q2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int townCount = Integer.parseInt(st.nextToken());
        int connectionCount = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        Map<Integer, ArrayList<Integer>> destinations = new HashMap<>(); //Integer start, Arraylist of Integer hash of destination and cost
        for (int i = 0; i < connectionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int town1 = Integer.parseInt(st.nextToken());
            int town2 = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            if (!destinations.containsKey(town1)) {
                destinations.put(town1, new ArrayList<>());
            }
            if (!destinations.containsKey(town2)) {
                destinations.put(town2, new ArrayList<>());
            }
            destinations.get(town1).add(town2 * 1000000 + cost);
            destinations.get(town2).add(town1 * 1000000 + cost);
        }

        int minCost = Integer.MAX_VALUE;
        int[][] visited = new int[townCount + 1][2]; //stores town and lowest cost
        for (int i = 0; i < visited.length; i++) {
            visited[i][1] = Integer.MAX_VALUE;
        }
        Queue<State> states = new LinkedList<>();
        states.add(new State(0, start));
        while (!states.isEmpty()) {
            State currState = states.remove();
            if (visited[currState.town][0] == 1 && visited[currState.town][1] < currState.cost) continue;
            if (currState.town == end) {
                minCost = Math.min(minCost, currState.cost);
            }
            visited[currState.town][0] = 1;
            visited[currState.town][1] = Math.min(visited[currState.town][1], currState.cost);
            ArrayList<Integer> foundDestinations = destinations.get(currState.town);
            if (foundDestinations != null) {
                for (int i = 0; i < foundDestinations.size(); i++) {
                    int hash = foundDestinations.get(i);
                    State newState = new State(currState.cost + hash % 1000000, (hash - (hash % 1000000)) / 1000000);
                    if (newState.town >= 0) states.add(newState);
                }
            }
        }
        System.out.println(minCost);
    }
    static class State {
        int cost;
        int town;
        State(int cost, int town) {
            this.cost = cost;
            this.town = town;
        }
    }
}
