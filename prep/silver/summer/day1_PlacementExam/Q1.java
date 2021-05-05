package placement;

import java.util.ArrayList;
import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int min = in.nextInt();
        while (true) {
            int pair = getSum(findDivisor(min));
            if (getSum(findDivisor(pair)) == min) {
                if (getSum(findDivisor(pair)) != getSum(findDivisor(min))) {
                    System.out.println((getSum(findDivisor(pair)) + " " + getSum(findDivisor(min))));
                    break;
                }
            }
            min++;
        }
    }
    private static ArrayList<Integer> findDivisor(int in) {
        ArrayList<Integer> factors = new ArrayList<>();
        factors.add(1);
        int minPair = in;
        for (int i = 2; i < minPair; i++) {
            if (in/i == (double)in/i) {
                factors.add(i);
                factors.add(in/i);
                minPair = in/i;
            }
        }
        return factors;
    }
    private static int getSum(ArrayList<Integer> in) {
        int sum = 0;
        for (int i = 0; i < in.size(); i++) {
            sum += in.get(i);
        }
        return sum;
    }
}