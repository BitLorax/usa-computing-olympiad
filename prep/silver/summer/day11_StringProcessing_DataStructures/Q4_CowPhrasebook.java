package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q4_CowPhrasebook {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int phraseCount = Integer.parseInt(st.nextToken());
        int queryCount = Integer.parseInt(st.nextToken());
        String[] phrases = new String[phraseCount];
        for (int i = 0; i < phraseCount; i++) {
            phrases[i] = in.readLine();
        }
        int matches = 0;
        for (int i = 0; i < queryCount; i++) {
            String test = in.readLine();
            for (int j = 0; j < phrases.length; j++) {
                String phrase = phrases[j];
                if (phrase.length() >= test.length() && phrase.substring(0, test.length()).equals(test)) {
                    matches++;
                    break;
                }
            }
        }
        System.out.println(matches);
    }
}
