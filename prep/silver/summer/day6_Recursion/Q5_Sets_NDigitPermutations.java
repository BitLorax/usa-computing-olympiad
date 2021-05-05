package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q5_Sets_NDigitPermutations {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(in.readLine());
        ArrayList<Integer> nums = new ArrayList<Integer>();
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < m; i++) {
            nums.add(Integer.parseInt(st.nextToken()));
        }
        int n = Integer.parseInt(in.readLine());
        getPermutations(nums, n, "");
    }
    private static void getPermutations(ArrayList<Integer> nums, int n, String ans) {
        ArrayList<Integer> NUMS = clone(nums);
        for (int num : nums) {
            String newAns = ans;
            nums = clone(NUMS);
            if (n > 1) {
                newAns += num;
                nums.remove(nums.indexOf(num));
                getPermutations(nums, n - 1, newAns);
            } else {
                newAns += num;
                System.out.println(newAns);
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
}
