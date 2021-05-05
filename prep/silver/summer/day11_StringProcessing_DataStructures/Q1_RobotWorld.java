package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Q1_RobotWorld {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int haybale = 1;
        Stack<Integer> storage = new Stack<>();
        int commandCount = Integer.parseInt(in.readLine());
        for (int i = 0; i < commandCount; i++) {
            String command = in.readLine();
            if (command.equals("ADD")) {
                storage.push(haybale);
                haybale++;
            } else {
                storage.pop();
            }
        }
        System.out.println(storage.size());
        for (int haybaleNum : storage) {
            System.out.println(haybaleNum);
        }
    }
}
