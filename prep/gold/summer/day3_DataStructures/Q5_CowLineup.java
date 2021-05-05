package day3_DataStructures;

import java.io.*;
import java.util.*;

@SuppressWarnings("unchecked")
public class Q5_CowLineup {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        Cow[] cows = new Cow[cowCount];
        Set<Integer> breeds = new HashSet<>();
        for (int i = 0 ; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int pos = Integer.parseInt(st.nextToken());
            int breed = Integer.parseInt(st.nextToken());
            breeds.add(breed);
            cows[i] = new Cow(pos, breed);
        }
        int maxBreed = breeds.size();
        Arrays.sort(cows);
        int minDist = Integer.MAX_VALUE;

        Map<Integer, Integer> breedRecord = new TreeMap<>();
        int right = 0;
        int left = 0;
        while (breedRecord.size() != maxBreed) {
            if (!breedRecord.containsKey(cows[right].breed)) {
                breedRecord.put(cows[right].breed, 0);
            }
            breedRecord.put(cows[right].breed, breedRecord.get(cows[right].breed) + 1);
            right++;
        }
        right--;

        while (true) {
            breedRecord.put(cows[left].breed, breedRecord.get(cows[left].breed) - 1);
            if (breedRecord.get(cows[left].breed) == 0) {
                breedRecord.put(cows[left].breed, breedRecord.get(cows[left].breed) + 1);
                break;
            }
            left++;
        }

        minDist = Math.min(minDist, cows[right].pos - cows[left].pos);

        while (true) {
            boolean end = false;
            while (cows[right].breed != cows[left].breed) {
                right++;
                if (right >= cows.length) {
                    end = true;
                    break;
                }
                breedRecord.put(cows[right].breed, breedRecord.get(cows[right].breed) + 1);
            }
            while (true) {
                breedRecord.put(cows[left].breed, breedRecord.get(cows[left].breed) - 1);
                if (breedRecord.get(cows[left].breed) == 0) {
                    breedRecord.put(cows[left].breed, breedRecord.get(cows[left].breed) + 1);
                    break;
                }
                left++;
            }
            if (end) break;
            minDist = Math.min(minDist, cows[right].pos - cows[left].pos);

        }
        System.out.println(minDist);
    }
    static class Cow implements Comparable<Cow> {
        int pos;
        int breed;
        Cow(int pos, int breed) {
            this.pos = pos;
            this.breed = breed;
        }
        public int compareTo(Cow a) {
            return this.pos - a.pos;
        }
    }
}
