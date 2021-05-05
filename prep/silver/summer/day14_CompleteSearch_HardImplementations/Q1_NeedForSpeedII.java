package day14_CompleteSearch_HardImplementations;

import java.util.Scanner;

public class Q1_NeedForSpeedII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int carForce = in.nextInt();
        int carMass = in.nextInt();

        int partCount = in.nextInt();
        int[][] partInfo = new int[partCount][2];
        for (int i = 0; i < partCount; i++) {
            partInfo[i][0] = in.nextInt();
            partInfo[i][1] = in.nextInt();
        }
        int maxPartRecord = 0;
        double maxAcce = carForce / carMass;
        for (int i = 0; i < (1 << partCount); i++) { //every combination of 1's and 0's
            int currForce = carForce;
            int currMass = carMass;
            for (int j = 0; j < partCount; j++) { //2^j = 1 << j
                if ((i & (1 << j)) != 0) { //& compares binary, checking if some digit of i is 1 (chose that part)
                    currForce += partInfo[j][0];
                    currMass += partInfo[j][1];
                }
            }
            if ((1.0 * currForce / currMass) > maxAcce) {
                maxPartRecord = i;
                maxAcce = 1.0 * currForce / currMass;
            }
        }
        boolean noParts = true;
        for (int j = 0; j < partCount; j++) {
            if ((maxPartRecord & (1 << j)) != 0) {
                System.out.println(j + 1);
                noParts = false;
            }
        }
        if (noParts) {
            System.out.println("NONE");
        }
    }
}
