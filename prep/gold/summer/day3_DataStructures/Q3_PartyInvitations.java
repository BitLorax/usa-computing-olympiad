package day3_DataStructures;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Q3_PartyInvitations {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int cowCount = Integer.parseInt(st.nextToken());
        int groupCount = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] cows = new ArrayList[cowCount];
        for (int i = 0; i < cowCount; i++) {
            cows[i] = new ArrayList<>();
        }
        ArrayList<Integer>[] groupInfo = new ArrayList[groupCount];
        for (int i = 0; i < groupCount; i++) {
            st = new StringTokenizer(in.readLine());
            int groupSize = Integer.parseInt(st.nextToken());
            groupInfo[i] = new ArrayList<>();
            for (int j = 0; j < groupSize; j++) {
                int cow = Integer.parseInt(st.nextToken()) - 1;
                groupInfo[i].add(cow);
                cows[cow].add(i);
            }
        }
        boolean[] invite = new boolean[20100];
        int invited = 1;
        Queue<Integer> invitedCows = new LinkedList<>();
        invitedCows.add(0);
        while (!invitedCows.isEmpty()) {
            int invitedCow = invitedCows.remove();
            invite[invitedCow] = true;
            for (int i : cows[invitedCow]) {
                if (groupInfo[i].size() == 0) continue;
                groupInfo[i].remove(groupInfo[i].indexOf((int)invitedCow));
                if (groupInfo[i].size() == 1) {
                    if (!invite[groupInfo[i].get(0)]) {
                        invitedCows.add(groupInfo[i].get(0));
                        invited++;
                        invite[groupInfo[i].get(0)] = true;
                    }
                    groupInfo[i].remove(0);
                }
            }
        }
        System.out.println(invited);
    }

}
