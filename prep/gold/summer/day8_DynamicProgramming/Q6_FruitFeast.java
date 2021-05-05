package day8_DynamicProgramming;

import java.io.*;
import java.util.StringTokenizer;

public class Q6_FruitFeast {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int capacity = Integer.parseInt(st.nextToken());
        int[] choices = new int[2];
        choices[0] = Integer.parseInt(st.nextToken());
        choices[1] = Integer.parseInt(st.nextToken());
        boolean[] possibilities = new boolean[capacity + 1];
        possibilities[0] = true;
        for (int i = 0; i <= capacity; i++) {
            if (i >= choices[0] && possibilities[i - choices[0]]) possibilities[i] = true;
            if (i >= choices[1] && possibilities[i - choices[1]]) possibilities[i] = true;
        }
        for (int i = 0; i <= capacity; i++) if (possibilities[i]) possibilities[i / 2] = true;
        for (int i = 0; i <= capacity; i++) {
            if (i >= choices[0] && possibilities[i - choices[0]]) possibilities[i] = true;
            if (i >= choices[1] && possibilities[i - choices[1]]) possibilities[i] = true;
        }
        for (int i = capacity; i >= 0; i--) {
            if (possibilities[i]) {
                System.out.println(i);
                break;
            }
        }
    }
}
