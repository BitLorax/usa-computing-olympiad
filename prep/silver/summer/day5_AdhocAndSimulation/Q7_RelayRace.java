package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Q7_RelayRace {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cowCount = Integer.parseInt(in.readLine());
        CowInfo[] cowInfos = new CowInfo[cowCount];
        for (int i = 0; i < cowCount; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int time = Integer.parseInt(st.nextToken());
            int cowStarts = Integer.parseInt(st.nextToken());
            int[] cowSignals = new int[cowStarts];
            for (int j = 0; j < cowStarts; j++) {
                cowSignals[j] = Integer.parseInt(st.nextToken());
            }
            cowInfos[i] = new CowInfo(i + 1, time, cowSignals);
        }
        Map<Integer, Integer> record = new HashMap<>();
        boolean finished = false;
        record.put(cowInfos[0].id, cowInfos[0].time); //cow1 start
        boolean[] finishedCows = new boolean[cowCount];
        int time = 0;

        while (!finished) {
            time++;
            for (int id : record.keySet()) {
                record.put(id, record.get(id) - 1);
            } //decrease time
            ArrayList<Integer> cowsFinished = checkFinished(record);
            for (int finishedCow : cowsFinished) {
                record.remove(finishedCow);
                finishedCows[finishedCow - 1] = true;
                int[] cowStart = cowInfos[finishedCow - 1].cowSignals;
                for (int cow : cowStart) {
                    if (!finishedCows[cow - 1] && !record.containsKey(cow)) {
                        record.put(cow, cowInfos[cow - 1].time);
                    }
                }
            }
            if (record.size() == 0) {
                finished = true;
            }
        }
        System.out.println(time);
    }
    private static ArrayList<Integer> checkFinished(Map<Integer, Integer> record) {
        ArrayList<Integer> finished = new ArrayList<>();
        for (int id : record.keySet()) {
            if (record.get(id) == 0) {
                finished.add(id);
            }
        }
        return finished;
    }
    static class CowInfo {
        int id;
        int time;
        int[] cowSignals;
        CowInfo(int id, int time, int[] cowSignals) {
            this.id = id;
            this.time = time;
            this.cowSignals = cowSignals;
        }
    }
}
