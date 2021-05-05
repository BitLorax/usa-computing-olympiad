package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")

public class Q8_DiamondCollector {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int diamondCount = Integer.parseInt(st.nextToken());
        int limit = Integer.parseInt(st.nextToken());
        int[] diamonds = new int[diamondCount];
        for (int i = 0; i < diamondCount; i++) {
            diamonds[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(diamonds);
        int[] diamondsInCase = new int[diamondCount]; //how many diamonds a case with min i diamond would contain
        for (int i = 0; i < diamondCount; i++) {
            int maxThreshold = diamonds[i] + limit;
            int maxIndex = Arrays.binarySearch(diamonds, maxThreshold);
            int temp = maxIndex;
            if (maxIndex < 0) {
                maxIndex = (maxIndex + 1) * -1;
            } else {
                while (diamonds[maxIndex] == diamonds[temp]) {
                    maxIndex++;
                    if (maxIndex >= diamonds.length) {
                        break;
                    }
                }
            }
            diamondsInCase[i] = maxIndex - i;
        }
        int maxDiamonds = 0;
        for (int i = 0; i < diamondCount; i++) {
            int diamondsCased = diamondsInCase[i];
            for (int j = i + diamondsCased; j < diamondCount; j++) {
                maxDiamonds = Math.max(maxDiamonds, diamondsCased + diamondsInCase[j]);
            }
        }
        System.out.println(maxDiamonds);
    }
}
