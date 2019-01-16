package silver.usaco2016;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class P1_WhyDidTheCowCrossTheRoadI {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/helpcross.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/helpcross.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int chickenCount = Integer.parseInt(st.nextToken());
        int cowCount = Integer.parseInt(st.nextToken());

        int[] chickens = new int[chickenCount];
        for (int i = 0; i < chickenCount; i++) {
            chickens[i] = Integer.parseInt(in.readLine());
        }
        Arrays.sort(chickens);

        Cow[] cows = new Cow[cowCount];
        for (int i = 0; i < cowCount; i++) {
            st = new StringTokenizer(in.readLine());
            cows[i] = new Cow(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(cows, new Comp());

        int chicken;
        int crossings = 0;
        for (int i = 0; i < cowCount; i++) {
            chicken = 0;
            while (true) {
                if (chicken >= chickenCount) break; //out of bounds
                if (chickens[chicken] > cows[i].end) break; //surpassed end limit
                if (chickens[chicken] > cows[i].start && chickens[chicken] < cows[i].end) { //found available chicken
                    chickens[chicken] = -1;
                    crossings++;
                    break;
                }
                chicken++;
            }
        }

        out.println(crossings);
        out.close();
    }
    static class Cow {
        int start;
        int end;
        Cow(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    static class Comp implements Comparator<Cow> {
        public int compare(Cow a, Cow b) {
            if (a.end == b.end) {
                return a.start - b.start;
            }
            return a.end - b.end;
        }
    }
}
