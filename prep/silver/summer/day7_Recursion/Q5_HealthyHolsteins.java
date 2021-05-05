package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q5_HealthyHolsteins {
    private static ArrayList<Integer> bestFeeds = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int vitaminCount = Integer.parseInt(in.readLine());
        int[] requirements = new int[vitaminCount];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < vitaminCount; i++) {
            requirements[i] = Integer.parseInt(st.nextToken());
        }
        int feedCount = Integer.parseInt(in.readLine());
        int[][] feedInfo = new int[feedCount][vitaminCount];
        for (int i = 0; i < feedCount; i++) {
            st = new StringTokenizer(in.readLine());
            for (int j = 0; j < vitaminCount; j++) {
                feedInfo[i][j] = Integer.parseInt(st.nextToken());
            }
        } //read everything in

        int[] currVitamin = new int[vitaminCount];
        boolean[] used = new boolean[feedInfo.length];
        int i = getMinScoops(requirements, feedInfo, 0, currVitamin, Integer.MAX_VALUE, used, 0, new ArrayList<>());

        System.out.print(i + " ");
        Collections.sort(bestFeeds);
        for (int num : bestFeeds) {
            System.out.print(num + " ");
        } //print everything out
    }

    /*
    Recursive method that goes over the feeds until the requirement is met
    It then compares it with other results and finds the smallest one

    @param requirements   stores the required amount of each vitamin
    @param feedInfo       records the vitamin amount of each feed
    @param scoopCount     counts how many feeds have been used
    @param currVitamin    stores the vitamin amounts according to what feeds have been consumed
    @param min            stores the minimum amount of scoopCount that meets the requirements
    @param used           records what feeds have been used (cannot use it twice)
    @param start          stores when to start the loop as to avoid repetition
    @param feeds          stores the feed numbers that have been consumed
    @return min           minimum amount of feeds needed to be consumed in order to meet the requirements

    Note: bestFeeds is changed according to the best combination of feeds to consume
     */
    private static int getMinScoops(int[] requirements, int[][] feedInfo, int scoopCount, int[] currVitamin, int min, boolean[] used, int start, ArrayList<Integer> feeds) {
        //information that should be the same for each loop
        int SCOOP_COUNT = scoopCount;
        int[] CURR_VITAMIN = currVitamin.clone();
        ArrayList<Integer> FEEDS = clone(feeds);
        boolean[] USED = used.clone();
        for (int i = start; i < feedInfo.length; i++) {
            //reset everything to how it should be, not what it is after the previous loop changed it
            used = USED.clone();
            if (!used[i]) {
                currVitamin = CURR_VITAMIN.clone();
                scoopCount = SCOOP_COUNT;
                feeds = clone(FEEDS); //reset
                int[] info = feedInfo[i];
                for (int j = 0; j < info.length; j++) {
                    currVitamin[j] += info[j];
                } //add feed
                scoopCount++;
                used[i] = true;
                feeds.add(i + 1);
                if (!testIfFulfilled(currVitamin, requirements)) {
                    min = Math.min(getMinScoops(requirements, feedInfo, scoopCount, currVitamin, min, used, i + 1, feeds), min);
                } else {
                    if (scoopCount < min) {
                        min = scoopCount;
                        bestFeeds = clone(feeds);
                    }
                    return Math.min(min, scoopCount);
                }
            }
        }
        return min;
    }
    private static boolean testIfFulfilled(int[] test, int[] requirements) {
        boolean result = true;
        for (int i = 0; i < test.length; i++) {
            if (test[i] < requirements[i]) {
                result = false;
            }
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
}
