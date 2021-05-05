package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q7_Sets_Subsets {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(in.readLine());
        StringTokenizer st = new StringTokenizer(in.readLine());
        ArrayList<Integer> nums = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            nums.add(Integer.parseInt(st.nextToken()));
        }
        for (int i = 1; i <= m; i++) {
            getCombinations(nums, i, "", new ArrayList<>());
        }
    }
    private static void getCombinations(ArrayList<Integer> nums, int n, String ans, ArrayList<String> used) {
        ArrayList<Integer> NUMS = clone(nums);
        for (int num : nums) {
            String newAns = ans;
            if (n > 1) {
                nums = clone(NUMS);
                newAns += num;
                nums.remove(nums.indexOf(num));
                getCombinations(nums, n - 1, newAns, used);
            } else {
                newAns += num;
                if (!checkIfSame(newAns, used)) {
                    System.out.println(newAns);
                    used.add(newAns);
                }
            }
        }
    }
    private static ArrayList<Integer> clone(ArrayList<Integer> in) {
        ArrayList<Integer> out = new ArrayList<>();
        for (int num : in) {
            out.add(num);
        }
        return out;
    }
    private static boolean checkIfSame(String test, ArrayList<String> used) {
        boolean result = false;
        int[] testLst = new int[test.length()];
        for (int i = 0; i < test.length(); i++) {
            testLst[i] = Integer.parseInt(test.substring(i, i + 1));
        }
        Arrays.sort(testLst);
        for (String combination : used) {
            int[] combinationLst = new int[combination.length()];
            for (int i = 0; i < combination.length(); i++) {
                combinationLst[i] = Integer.parseInt(combination.substring(i, i + 1));
            }
            Arrays.sort(combinationLst);
            if (Arrays.equals(testLst, combinationLst)) {
                result = true;
                break;
            }
        }
        return result;
    }
}
