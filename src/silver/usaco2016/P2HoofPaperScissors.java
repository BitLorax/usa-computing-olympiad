package silver.usaco2016;

import java.io.*;

public class P2HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/silver/resources2016/hps.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources2016/hps.out")));

        int rounds = Integer.parseInt(in.readLine());
        int[] results = new int[rounds];

        for (int round = 0; round < rounds; round++) {
            String move = in.readLine();
            results[round] = moveToInt(move.charAt(0)); // Paper, Hoof, Scissors -> 1, 2, 3
        }

        int maxWins = 0;
        int currWins;
        int[] wins1 = new int[3];
        int[] wins2 = initializeWinValues(results);
        for (int switchPoint = 0; switchPoint < rounds; switchPoint++) {
            for (int choice = 1; choice < 4; choice++) { // First part
                if (calcResult(choice, results[switchPoint])) { // Only update the new prefix
                    wins1[choice - 1]++;
                }
                if (switchPoint != 0) {
                    if (calcResult(choice, results[switchPoint])) {
                        wins2[choice - 1] -= 1;
                    }
                }
            }

            // Calculate maximum amount of wins and compare
            int currMaxWins1 = 0;
            int currMaxWins2 = 0;
            for (int wins = 0; wins < 3; wins++) {
                currMaxWins1 = Math.max(currMaxWins1, wins1[wins]);
                currMaxWins2 = Math.max(currMaxWins2, wins2[wins]);
            }
            currWins = currMaxWins1 + currMaxWins2;
            maxWins = Math.max(maxWins, currWins);
        }

        out.println(maxWins);
        out.close();
    }

    private static int moveToInt(char move) {
        if (move == 'P') {
            return 1;
        } else if (move == 'H') {
            return 2;
        } else if (move == 'S') {
            return 3;
        } else {
            return -1;
        }
    }

    private static boolean calcResult(int move1, int move2) { // returns result in perspective of move1
        return move1 + 1 == move2 || move1 - 2 == move2;
    }

    private static int[] initializeWinValues(int[] results) {
        int[] wins = new int[3];
        for (int move : results) {
            wins[(results[move] + 1) % 3]++;
        }
        return wins;
    }
}

