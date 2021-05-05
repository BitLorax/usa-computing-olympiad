package placement;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        int limit = Integer.parseInt(st.nextToken());
        int bucketCount = Integer.parseInt(st.nextToken());
        String[] bucketsString = in.nextLine().split(" ");
        ArrayList<Integer> buckets = new ArrayList<>();
        for (int i = 0; i < bucketsString.length; i++) {
            buckets.add(Integer.parseInt(bucketsString[i]));
        }
        ArrayList<Integer> results = new ArrayList<>();

        for (int i = 0; i < buckets.size(); i++) {
            results = maxFeed(buckets, i, limit, 0, results);
        }

        int max = 0;
        for (int i = 0; i < results.size(); i++) {
            max = Math.max(max, results.get(i));
        }
        System.out.println(max);
    }
    private static ArrayList<Integer> maxFeed(ArrayList<Integer> buckets, int index, int max, int currAmount, ArrayList<Integer> results) {// start is index
        if (buckets.get(index) + currAmount <= max) {
            currAmount += buckets.get(index);
            ArrayList<Integer> newBuckets = new ArrayList<>();
            for (int i = 0; i < buckets.size(); i++) {
                newBuckets.add(buckets.get(i));
            }
            newBuckets.remove(index);
            for (int i = 0; i < newBuckets.size(); i++) {
                maxFeed(newBuckets, i, max, currAmount, results);
            }
        } else {
            results.add(currAmount);
        }
        return results;
    }
}
