package day2_SearchingAndSorting;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q7_CitiesAndStates {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int pairCount = Integer.parseInt(in.readLine());
        Map<String, Long> count = new HashMap<>();
        for(int i = 0; i < pairCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            String city = st.nextToken();
            String state = st.nextToken();
            if(!city.substring(0, 2).equals(state)) {
                String key = city.substring(0, 2) + state;
                if(!count.containsKey(key)) {
                    count.put(key, 0L);
                }
                count.put(key, count.get(key) + 1);
            }
        }
        long pairs = 0;
        for(String key: count.keySet()) {
            String otherKey = key.substring(2) + key.substring(0, 2);
            if(count.containsKey(otherKey)) {
                pairs += count.get(key) * count.get(otherKey);
            }
        }
        System.out.println(pairs / 2);
    }
}
