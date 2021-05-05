package day7_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q6_Coggle {
    private static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
    private static int[] dy = {0, 0, 1, -1, 1, -1, 1, -1};
    private static char[][] board;
    private static boolean wordFound = false;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        board = new char[5][5];
        for (int i = 0; i < 5; i++) {
            String row = in.readLine();
            for (int j = 0; j < 5; j++) {
                board[j][i] = row.charAt(2 * j);
            }
        }
        int wordsFormed = 0;
        while (in.ready()) {
            wordFound = false;
            canFindWord(in.readLine());
            if (wordFound) {
                wordsFormed++;
            }
        }
        System.out.println(wordsFormed);
    }
    private static void canFindWord(String word) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == word.charAt(0)) {
                    findWord(word, i, j, 1);
                    if (wordFound) {
                        return;
                    }
                }
            }
        }
    }
    private static void findWord(String word, int x, int y, int index) {
        if (index >= word.length()) {
            wordFound = true;
            return;
        }
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) continue;
            if (board[newX][newY] == word.charAt(index)) {
                board[newX][newY] = '#';
                findWord(word, newX, newY, index + 1);
                board[newX][newY] = word.charAt(index);
            }
        }
    }
}
