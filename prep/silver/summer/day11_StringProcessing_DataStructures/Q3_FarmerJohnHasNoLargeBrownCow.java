package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q3_FarmerJohnHasNoLargeBrownCow {
    private static ArrayList<ArrayList<String>> adjectives = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int missing = Integer.parseInt(st.nextToken());
        int cowNum = Integer.parseInt(st.nextToken());
        for (int i = 0; i < missing; i++) {
            st = new StringTokenizer(in.readLine());
            st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            String adj;
            int j = 0;
            while (!(adj = st.nextToken()).equals("cow")) {
                if (adjectives.size() < j + 1) {
                    adjectives.get(j).add(adj);
                    j++;
                }
            }
        }
    }
}
