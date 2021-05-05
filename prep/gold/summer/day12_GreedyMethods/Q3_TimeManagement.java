package day12_GreedyMethods;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Q3_TimeManagement {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int jobCount = Integer.parseInt(in.readLine());
        Job[] jobs = new Job[jobCount];
        for (int i = 0; i < jobCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            jobs[i] = new Job(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(jobs);
        int time = 1000000;
        for (int i = 0; i < jobCount; i++) {
            if (jobs[i].deadline < time) time = jobs[i].deadline;
            time -= jobs[i].timeRequired;
        }
        if (time >= 0) System.out.println(time);
        else System.out.println(-1);
    }
    static class Job implements Comparable<Job> {
        int deadline;
        int timeRequired;
        Job (int t, int d) {
            timeRequired = t;
            deadline = d;
        }
        public int compareTo(Job a) {
            return a.deadline - this.deadline;
        }
    }
}
