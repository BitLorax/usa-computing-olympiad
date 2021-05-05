package day2_SearchingAndSorting;

import java.util.*;

public class Q5_NeedForSpeed {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(in.nextLine());
        CarInfo car = new CarInfo(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        int partCount = Integer.parseInt(st.nextToken());
        partInfo[] partInfos = new partInfo[partCount];
        for (int i = 0; i < partCount; i++) {
            st = new StringTokenizer(in.nextLine());
            partInfos[i] = new partInfo(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), i + 1);
        }
        Arrays.sort(partInfos);
        ArrayList<Integer> acceptedParts = new ArrayList<>();
        for (int i = partInfos.length - 1; i >= 0; i--) {
            if (partInfos[i].ratio > car.ratio) {
                acceptedParts.add(partInfos[i].id);
                car.changeInfo(partInfos[i].f, partInfos[i].m);
            }
        }
        Collections.sort(acceptedParts);
        if (acceptedParts.size() == 0) {
            System.out.println("NONE");
        } else {
            for (int i = 0; i < acceptedParts.size(); i++) {
                System.out.println(acceptedParts.get(i));
            }
        }
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
