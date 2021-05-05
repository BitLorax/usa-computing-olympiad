package day3_DataStructures;

import java.io.*;
import java.util.*;

public class Q1_CityHorizon {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int buildingCount = Integer.parseInt(in.readLine());
        Point[] points = new Point[buildingCount * 2];
        for (int i = 0; i < buildingCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            long j = Integer.parseInt(st.nextToken());
            long k = Integer.parseInt(st.nextToken());
            long l = Integer.parseInt(st.nextToken());
            points[i * 2] = new Point(j, l);
            points[i * 2 + 1] = new Point(k, -1 * l);
        }
        Arrays.sort(points);

        long area = 0;
        long currHeight = 0;
        Map<Long, Integer> heights = new TreeMap<>();
        //TreeSet<ArrayList<Long>> heights = new TreeSet<>();
        for (int i = 0; i < buildingCount * 2 - 1; i++) {
            int k = i;
            long maxUp = 0;
            long maxDown = 0;
            while (points[k].pos == points[i].pos) {
                maxUp = Math.max(points[i].height, maxUp);
                maxDown = Math.min(points[i].height, maxDown);
                if (points[i].height > 0) {
                    if (!heights.containsKey(points[i].height)) {
                        heights.put(points[i].height, 0);
                    }
                    heights.put(points[i].height, heights.get(points[i].height) + 1);
                }
                if (points[i].height < 0) {
                    heights.put(points[i].height * -1, heights.get(points[i].height * -1) - 1);
                    if (heights.get(points[i].height * -1) <= 0) heights.remove(points[i].height * -1);
                }
                i++;
            }
            i--;
            long j = points[i + 1].pos - points[k].pos;
            if (currHeight == (maxDown * -1) || maxUp > currHeight) {
                if (maxUp > currHeight) { //a building is taller
                    currHeight = maxUp;
                }
                if ((maxDown * -1) == currHeight) { //the tallest building ends
                    if (heights.size() > 0) currHeight = ((TreeMap<Long, Integer>) heights).lastKey();
                    else currHeight = 0;
                }
            }
            area += currHeight * j;

        }

        /*
        long area = 0;
        int currHeight = 0;
        int overlap = 0;
        for (int i = 0; i < buildingCount * 2 - 1; i++) { //don't visit last point, no need
            int k = i;
            int maxUp = points[i].height;
            while (points[i].pos == points[i + 1].pos) {
                maxUp += points[++i].height;
            }
            int j = points[i + 1].pos - points[k].pos;
            if (maxUp > currHeight) {
                overlap += currHeight;
            } else {
                if (maxUp >= 0 || (maxUp * -1) < currHeight && overlap != 0) {
                    overlap += maxUp;
                }
            }
            currHeight += maxUp;
            area += (currHeight - overlap) * j;
        }
        */
        System.out.println(area);
    }
    static class Point implements Comparable<Point>{
        long pos;
        long height; //change
        Point(long pos, long height) {
            this.height = height;
            this.pos = pos;
        }
        public int compareTo(Point a) {
            return (int)(this.pos - a.pos);
        }
    }
}
