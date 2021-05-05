package day14_CompleteSearch_HardImplementations;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Q3_TheBaleTowerII {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int haybaleCount = in.nextInt();
        int[][] haybaleInfo = new int[haybaleCount][2];
        for (int i = 0; i < haybaleCount; i++) {
            haybaleInfo[i][0] = in.nextInt();
            haybaleInfo[i][1] = in.nextInt();
        }

        int maxHeight = 0;
        for (int i = 0; i < (1 << haybaleCount); i++) {
            Map<Integer, Integer> tower = new TreeMap<>();
            for (int j = 0; j < haybaleCount; j++) { //put everything chosen into the TreeMap
                if ((i & (1 << j)) != 0) {
                    tower.put(haybaleInfo[j][0], haybaleInfo[j][1]);
                }
            }
            boolean validTower = true;
            int[] breadths = new int[tower.size()];
            int index = 0;
            for (int key : tower.keySet()) {
                breadths[index] = tower.get(key);
                index++;
            }
            for (int j = 1; j < breadths.length; j++) {
                if (breadths[j] < breadths[j - 1]) {
                    validTower = false;
                }
            }
            if (validTower) {
                maxHeight = Math.max(maxHeight, tower.size());
            }
        }
        System.out.println(maxHeight);
    }
}
