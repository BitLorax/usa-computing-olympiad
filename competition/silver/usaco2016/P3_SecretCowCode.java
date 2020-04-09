package silver.usaco2016;

import java.io.*;
import java.util.*;

public class P3_SecretCowCode {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/cowcode.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/cowcode.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        String pattern = st.nextToken();
        int oriLen = pattern.length();
        int index = Integer.parseInt(st.nextToken());

        while (pattern.length() < index) {
            pattern = pattern + pattern.charAt(pattern.length() - 1) + pattern.substring(0, pattern.length() - 1);
        }

        while (pattern.length() != oriLen) {
            int newLenPos = pattern.length() / 2; // start/end with this index
            if (newLenPos > index) {
                pattern = pattern.substring(0, newLenPos);
            } else {
                index -= newLenPos + 1;
                if (index == 0) {
                    index += newLenPos;
                }
                pattern = pattern.substring(newLenPos + 1, pattern.length()) + pattern.charAt(newLenPos);
            }
        }
        out.println(pattern.charAt(index - 1));

        out.close();
    }
}
