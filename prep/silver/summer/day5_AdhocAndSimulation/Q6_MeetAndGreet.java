package day5_AdhocAndSimulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q6_MeetAndGreet {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int bMoves = Integer.parseInt(st.nextToken());
        int eMoves = Integer.parseInt(st.nextToken());
        ArrayList<String> bInstructions = new ArrayList<>();
        ArrayList<String> eInstructions = new ArrayList<>();
        for (int i = 0; i < bMoves + eMoves; i++) {
            if (i < bMoves) {
                bInstructions.add(in.readLine());
            } else {
                eInstructions.add(in.readLine());
            }
        }

        int bPos = 0;
        int ePos = 0;
        int crosses = 0;
        boolean together = true;
        boolean finished = false;
        int bCounter = 0;
        int eCounter = 0;

        int bMag = 1;
        int bDirec = 0;
        int eMag = 1;
        int eDirec = 0;
        while (!finished) {
            if (bCounter == 1 && bInstructions.size() > 0) { //at start of every instruction
                st = new StringTokenizer(bInstructions.get(0));
                bMag = Integer.parseInt(st.nextToken());
                bDirec = getDirection(st.nextToken());
            }
            if (eCounter == 1 && eInstructions.size() > 0) { //at start of every instruction
                st = new StringTokenizer(eInstructions.get(0));
                eMag = Integer.parseInt(st.nextToken());
                eDirec = getDirection(st.nextToken());
            }
            bPos += bDirec;
            ePos += eDirec;
            if (bPos == ePos) {
                if (!together) {
                    crosses++;
                }
                together = true;
            } else {
                together = false;
            }
            if (bCounter == bMag) {
                bCounter = 0;
                bDirec = 0;
                if (bInstructions.size() > 0) {
                    bInstructions.remove(0);
                }
            }
            if (eCounter == eMag) {
                eCounter = 0;
                eDirec = 0;
                if (eInstructions.size() > 0) {
                    eInstructions.remove(0);
                }
            }
            bCounter++;
            eCounter++;
            if (bInstructions.size() == 0 && eInstructions.size() == 0) {
                finished = true;
            }
        }
        System.out.println(crosses);
    }
    private static int getDirection(String direc) {
        if (direc.equals("L")) {
            return -1;
        }
        return 1;
    }
}
