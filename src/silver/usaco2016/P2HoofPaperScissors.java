package silver.usaco2016;

/*

[Explanation]
First, create two arrays for the first choice and second choice with 3 slots each for each choice.
Calculate the maximum amount of wins with the certain switchPoint by taking the sum of the biggest values of the arrays.
Compare them to the maximum number of wins.
Update the table whenever the switchPoint changes.

With the sample input, the tables should look like this:
Switch location    | 0       | 1       | 2       | 3       | 4       |
Before & at switch:| 0, 0, 1 | 0, 0, 2 | 1, 0, 2 | 1, 0, 3 | 1, 1, 3 |
After switch:      | 1, 1, 2 | 1, 1, 1 | 0, 1, 1 | 0, 1, 0 | 0, 0, 0 |

This is the win-loss chain:
1 -> 2 -> 3 -> 1

 */

import java.io.*;

public class P2HoofPaperScissors {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/silver/resources/hps.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("src/silver/resources/hps.out")));

        int rounds = Integer.parseInt(br.readLine());
        int[] results = new int[rounds];

        for (int round = 0; round < rounds; round++) {
            String move = br.readLine();
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

        pw.println(maxWins);
        pw.close();
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

