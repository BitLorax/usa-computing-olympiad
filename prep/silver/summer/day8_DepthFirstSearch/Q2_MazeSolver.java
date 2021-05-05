package day8_DepthFirstSearch;

import java.io.*;
import java.util.*;

public class Q2_MazeSolver {
    private static char[] direcs = {'R', 'U', 'L', 'D'};
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        String[][] maze = new String[width][height];
        int[] currPos = new int[2];
        for (int i = 0; i < height; i++) {
            String k = in.readLine();
            for (int j = 0; j < width; j++) {
                maze[j][i] = k.substring(j, j + 1);
                if (maze[j][i].equals("S")) {
                    currPos[0] = j;
                    currPos[1] = i;
                }
            }
        }
        System.out.println(solve(maze, currPos, 1, new ArrayList<>()));
    }
    private static String solve(String[][] maze, int[] currPos, int direc, ArrayList<Integer> path) {
        direc--;
        if (direc < 0) {
            direc += 4;
        }
        while (checkIfBlocked(maze, currPos, direc)) {
            direc++;
        }
        path.add(direc);
        currPos = getNewPos(currPos, direcs[direc]);

        if (maze[currPos[0]][currPos[1]].equals("F")) {
            path = clean(path);
            return convert(path);
        }
        return solve(maze, currPos, direc, path);
    }
    private static boolean checkIfBlocked(String[][] maze, int[] currPos, int direc) {
        int[] pos = currPos.clone();
        pos = getNewPos(pos, direcs[direc]);
        return maze[pos[0]][pos[1]].equals("#");
    }
    private static int[] getNewPos(int[] pos, char direc) {
        switch (direc) {
            case 'R': pos[0]++;
            break;
            case 'U': pos[1]--;
            break;
            case 'L': pos[0]--;
            break;
            case 'D': pos[1]++;
            break;
        }
        return pos;
    }
    private static String convert(ArrayList<Integer> path) {
        String ans = "";
        for (int i : path) {
            ans += direcs[i];
        }
        return ans;
    }
    private static ArrayList<Integer> clean(ArrayList<Integer> path) { //gets rid of moves that result in equilibrium (ex: U and D)
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(path.get(0));
        for (int i = 1; i < path.size(); i++) {
            int j = path.get(i);
            if (ans.size() > 0) {
                if (Math.abs(ans.get(ans.size() - 1) - j) == 2) {
                    ans.remove(ans.size() - 1);
                } else {
                    ans.add(path.get(i));
                }
            } else {
                ans.add(path.get(i));
            }
        }
        return ans;
    }
}
