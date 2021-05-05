package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Q1_NeedForSpeed {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        CarInfo car = new CarInfo(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        int partCount = Integer.parseInt(st.nextToken());
        partInfo[] partInfos = new partInfo[partCount];
        for (int i = 0; i < partCount; i++) {
            st = new StringTokenizer(in.readLine());
            partInfos[i] = new partInfo(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), i + 1);
        }
        Arrays.sort(partInfos);
        ArrayList<Integer> ans = getParts(partInfos, car, 1, new ArrayList<>());
        Collections.sort(ans);
        for (int part : ans) {
            System.out.println(part);
        }
        if (ans.size() == 0) {
            System.out.println("NONE");
        }
    }
    private static ArrayList<Integer> getParts(partInfo[] partInfos, CarInfo car, int partIndex, ArrayList<Integer> ans) {
        if (partIndex <= partInfos.length) {
            partInfo part = partInfos[partInfos.length - partIndex];
            if (part.ratio > car.ratio) {
                ans.add(part.id);
                car.changeInfo(part.f, part.m);
                getParts(partInfos, car, ++partIndex, ans);
            } else {
                return ans;
            }
        }
        return ans;
    }
    static class partInfo implements Comparable<partInfo> {
        int f;
        int m;
        double ratio;
        int id;
        partInfo(int f, int m, int id) {
            this.f = f;
            this.m = m;
            this.ratio = (double)f / m;
            this.id = id;
        }
        public int compareTo(partInfo a) {
            return (int)(this.ratio - a.ratio);
        }
    }
    static class CarInfo {
        int f;
        int m;
        double ratio;
        CarInfo(int f, int m) {
            this.f = f;
            this.m = m;
            this.ratio = (double)f / m;
        }
        void changeInfo(int addF, int addM) {
            this.f += addF;
            this.m += addM;
            this.ratio = (double)f / m;
        }
    }
}
