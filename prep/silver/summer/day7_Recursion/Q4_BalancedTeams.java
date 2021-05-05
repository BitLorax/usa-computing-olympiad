package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Q4_BalancedTeams {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> cows = new ArrayList<>();
        for (int i = 0; i < 12; i++) {
            cows.add(Integer.parseInt(in.readLine()));
        }
        int minDiff = Integer.MAX_VALUE;
        ArrayList<Integer> COWS1 = clone(cows);
        Integer[] team = new Integer[3];
        ArrayList<Integer[]> teams1 = buildTeams(cows, 0, new ArrayList<>(), team, new ArrayList<>());
        for (int i = 0; i < teams1.size(); i++) {
            Integer[] team1 = teams1.get(i);
            cows = clone(COWS1);
            for (int cow : team1) {
                cows.remove(cows.indexOf(cow));
            }
            ArrayList<Integer> COWS2 = clone(cows);
            ArrayList<Integer[]> teams2 = buildTeams(cows, 0, new ArrayList<>(), team, new ArrayList<>());
            for (int j = 0; j < teams2.size(); j++) {
                Integer[] team2 = teams2.get(j);
                cows = clone(COWS2);
                for (int cow : team2) {
                    cows.remove(cows.indexOf(cow));
                }
                ArrayList<Integer> COWS3 = clone(cows);
                ArrayList<Integer[]> teams3 = buildTeams(cows, 0, new ArrayList<>(), team, new ArrayList<>());
                for (int k = 0; k < teams3.size(); k++) {
                    Integer[] team3 = teams3.get(k);
                    cows = clone(COWS3);
                    for (int cow : team3) {
                        cows.remove(cows.indexOf(cow));
                    }
                    Integer[] team4 = new Integer[3];
                    for (int l = 0; l < cows.size(); l++) {
                        team4[l] = cows.get(l);
                    }

                    int max = 0;
                    int min = Integer.MAX_VALUE;
                    max = Math.max(max, getSum(team1));
                    min = Math.min(min, getSum(team1));
                    max = Math.max(max, getSum(team2));
                    min = Math.min(min, getSum(team2));
                    max = Math.max(max, getSum(team3));
                    min = Math.min(min, getSum(team3));
                    max = Math.max(max, getSum(team4));
                    min = Math.min(min, getSum(team4));

                    minDiff = Math.min(minDiff, (max - min));
                }
            }
        }
        System.out.println(minDiff);
    }
    private static ArrayList<Integer[]> buildTeams(ArrayList<Integer> cows, int teamSize, ArrayList<Integer[]> ans, Integer[] currTeam, ArrayList<Integer[]> used) {
        Integer[] CURR_TEAM = currTeam.clone();
        ArrayList<Integer> COWS = clone(cows);
        int TEAM_SIZE = teamSize;
        for (int cow : cows) {
            teamSize = TEAM_SIZE;
            currTeam = CURR_TEAM.clone();
            cows = clone(COWS);
            if (teamSize < 2) {
                currTeam[teamSize] = cow;
                teamSize++;
                cows.remove(cows.indexOf(cow));
                ans = buildTeams(cows, teamSize, ans, currTeam, used);
            } else {
                currTeam[teamSize] = cow;
                if (!checkIfSame(currTeam, used)) {
                    ans.add(currTeam);
                    used.add(currTeam);
                }
            }
        }
        return ans;
    }
    private static Integer[] convert(int[] in) {
        Integer[] result = new Integer[in.length];
        for (int i = 0; i < in.length; i++) {
            result[i] = in[i];
        }
        return result;
    }
    private static ArrayList<Integer> clone(ArrayList<Integer> in) {
        ArrayList<Integer> out = new ArrayList<>();
        for (int num : in) {
            out.add(num);
        }
        return out;
    }
    private static boolean checkIfSame(Integer[] testLst, ArrayList<Integer[]> used) {
        boolean result = false;
        Arrays.sort(testLst);
        for (Integer[] combinationLst : used) {
            Arrays.sort(combinationLst);
            if (Arrays.equals(testLst, combinationLst)) {
                result = true;
                break;
            }
        }
        return result;
    }
    private static int getSum(Integer[] in) {
        int result = 0;
        for (int i : in) {
            result += i;
        }
        return result;
    }
}
