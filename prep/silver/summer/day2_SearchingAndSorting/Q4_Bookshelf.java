package day2_SearchingAndSorting;

import java.util.*;

public class Q4_Bookshelf {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int shelfHeight = Integer.parseInt(st.nextToken());
        int[] cowHeights = new int[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cowHeights[i] = Integer.parseInt(in.nextLine());
        }
        Arrays.sort(cowHeights);
        ArrayList<Integer> cowHeightsList = writeToAL(cowHeights);
        int currHeight = 0;
        int cows = 0;
        while (currHeight < shelfHeight) {
            currHeight += cowHeightsList.get(cowHeightsList.size() - 1);
            cowHeightsList.remove(cowHeightsList.size() - 1);
            cows++;
        }
        System.out.println(cows);
    }
    private static ArrayList<Integer> writeToAL(int[] in) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < in.length; i++) {
            result.add(in[i]);
        }
        return result;
    }
}
