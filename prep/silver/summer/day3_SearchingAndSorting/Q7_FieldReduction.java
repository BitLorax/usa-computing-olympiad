package day3_SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q7_FieldReduction {
    private static Coord[] coordsXSorted;
    private static Coord[] coordsYSorted;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        coordsXSorted = new Coord[cowCount];
        coordsYSorted = new Coord[cowCount];
        Coord[] removableCoords = new Coord[12]; //3 or min/max, (3 + 3) for each x and y
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            Coord temp = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            coordsXSorted[i] = temp;
            coordsYSorted[i] = temp;
        }
        Arrays.sort(coordsXSorted, new CompX());
        Arrays.sort(coordsYSorted, new CompY());

        int index = 0; //index to put in value for removableCoords
        for (int i = 0; i < 3; i++) {
            removableCoords[index] = coordsXSorted[i];
            index++;
            removableCoords[index] = coordsXSorted[cowCount - 1 - i];
            index++;
        }
        for (int i = 0; i < 3; i++) {
            removableCoords[index] = coordsYSorted[i];
            index++;
            removableCoords[index] = coordsYSorted[cowCount - 1 - i];
            index++;
        }
        int area = Integer.MAX_VALUE;
        for (int i = 0; i < removableCoords.length; i++) {
            for (int j = i + 1; j < removableCoords.length; j++) {
                for (int k = j + 1; k < removableCoords.length; k++) {
                    Coord[] removed = {removableCoords[i], removableCoords[j], removableCoords[k]};
                    area = Math.min(area, calcArea(removed));
                }
            }
        }
        System.out.println(area);
    }
    private static int calcArea(Coord[] removed) {
        int xMin = -1;
        int xMax = -1;
        boolean xMinFound = false;
        boolean xMaxFound = false;
        for (int i = 0; i < coordsXSorted.length; i++) {
            if (!contains(coordsXSorted[i], removed) && !xMinFound) {
                xMin = coordsXSorted[i].x;
                xMinFound = true;
            }
            if (!contains(coordsXSorted[coordsXSorted.length - 1 - i], removed) && !xMaxFound) {
                xMax = coordsXSorted[coordsXSorted.length - 1 - i].x;
                xMaxFound = true;
            }
            if (xMinFound && xMaxFound) {
                break;
            }
        }
        int yMin = -1;
        int yMax = -1;
        boolean yMinFound = false;
        boolean yMaxFound = false;
        for (int i = 0; i < coordsYSorted.length; i++) {
            if (!contains(coordsYSorted[i], removed) && !yMinFound) {
                yMin = coordsYSorted[i].y;
                yMinFound = true;
            }
            if (!contains(coordsYSorted[coordsYSorted.length - 1 - i], removed) && !yMaxFound) {
                yMax = coordsYSorted[coordsYSorted.length - 1 - i].y;
                yMaxFound = true;
            }
            if (yMinFound && yMaxFound) {
                break;
            }
        }
        return (Math.abs(xMax - xMin) * Math.abs(yMax - yMin));
    }
    private static boolean contains(Coord target, Coord[] lst) {
        for (Coord test : lst) {
            if (test.x == target.x && test.y == target.y) {
                return true;
            }
        }
        return false;
    }
    static class Coord {
        int x;
        int y;
        Coord (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static class CompX implements Comparator<Coord> {
        public int compare(Coord a, Coord b) {
            return a.x - b.x;
        }
    }
    static class CompY implements Comparator<Coord> {
        public int compare(Coord a, Coord b) {
            return a.y - b.y;
        }
    }
}
