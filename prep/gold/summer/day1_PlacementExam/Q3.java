package placement;

import java.io.*;
import java.util.*;

@SuppressWarnings("unchecked")

public class Q3 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int clumpCount = Integer.parseInt(st.nextToken());
        int pos = Integer.parseInt(st.nextToken());
        ArrayList<Integer> clumpLocations = new ArrayList<>();
        ArrayList<State> statesFound = new ArrayList<>();
        for (int i = 0; i < clumpCount; i++) {
            clumpLocations.add(Integer.parseInt(in.readLine())); //hash for positions and staleness
        }
        Collections.sort(clumpLocations);
        boolean start = true;
        int minStaleness = Integer.MAX_VALUE;
        Queue<State> states = new LinkedList<>();
        states.add(new State(pos, 0, 0, getNextClump(-1, clumpLocations, pos), getNextClump(1, clumpLocations, pos)));
        while (!states.isEmpty()) {
            State currState = states.remove();
            if (stateEncountered(statesFound, currState)) continue;
            if (currState.prev < 0 && currState.next >= clumpLocations.size()) {
                minStaleness = Math.min(minStaleness, currState.stalenessEaten);
                continue;
            }
            statesFound.add(currState);
            State temp = new State(-1, -1,  -1, -1, -1);
            State newState = new State(-1, -1,  -1, -1, -1);
            for (int i = -1; i< 2; i += 2) { //to get -1 and 1
                newState = new State(currState.pos, currState.stalenessEaten, currState.currStaleness, currState.prev, currState.next);
                int nextClump;
                if (i == -1) {
                    nextClump = newState.prev;
                } else {
                    nextClump = newState.next;
                }
                if (nextClump >= 0 && nextClump < clumpLocations.size()) { //valid clump
                    int diffPos = Math.abs(clumpLocations.get(nextClump) - currState.pos);
                    newState.pos = clumpLocations.get(nextClump);
                    newState.currStaleness += diffPos;
                    newState.stalenessEaten += newState.currStaleness;
                    if (i == -1) newState.prev -= 1;
                    if (i == 1) newState.next += 1;
                } else {
                    newState.currStaleness = Integer.MAX_VALUE;
                }
                if (i == -1) {
                    temp = new State(newState.pos, newState.stalenessEaten, newState.currStaleness, newState.prev, newState.next);
                }
            }
            if (temp.currStaleness - newState.currStaleness > 100000) {
                states.add(newState);
            } else if (newState.currStaleness - temp.currStaleness > 100000) {
                states.add(temp);
            } else {
                states.add(temp);
                states.add(newState);
            }
            start = false;
        }
        System.out.println(minStaleness);
    }
    private static int getNextClump(int direc, ArrayList<Integer> clumpLocations, int pos) { //returns index of clump position
        int i = Arrays.binarySearch(clumpLocations.toArray(), pos);
        if (i < 0) {
            i = (i + 1) * -1;
        }
        if (direc < 0) {
            return i - 1;
        } else {
            return i;
        }
    }
    private static boolean stateEncountered(ArrayList<State> found, State test) {
        for (State i : found) {
            //if (i.currStaleness == test.currStaleness && i.stalenessEaten == test.stalenessEaten && i.clumpLocations.equals(test.clumpLocations) && i.pos == test.pos) return true;
            if (i.pos == test.pos && i.stalenessEaten == test.stalenessEaten && i.currStaleness == test.currStaleness && i.prev == test.prev & i.next == test.next) return true;
        }
        return false;
    }
    static class State {
        int pos;
        int stalenessEaten;
        //ArrayList<Integer> clumpLocations;
        int currStaleness;
        int prev;
        int next;
        State(int pos, int stalenessEaten, int currStaleness, int prev, int next) {
            this.pos = pos;
            this.stalenessEaten = stalenessEaten;
            //this.clumpLocations = clumpLocations;
            this.currStaleness = currStaleness;
            this.prev = prev;
            this.next = next;
        }
    }
}
