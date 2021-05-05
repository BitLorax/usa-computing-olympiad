package day11_StringProcessing_DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

@SuppressWarnings("unchecked")

public class Q5_RegistersInTheShop {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int registerCount = Integer.parseInt(in.readLine());
        Queue<Integer> line = new LinkedList<>();
        ArrayList<Integer>[] registers = new ArrayList[registerCount];
        for (int i = 0; i < registers.length; i++) {
            registers[i] = new ArrayList<>();
        }
        while (in.ready()) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            String type = st.nextToken();
            int num = Integer.parseInt(st.nextToken());
            if (type.equals("C")) {
                line.add(num);
            } else if (type.equals("R")) {
                registers[num - 1].add(line.remove());
            }
        }
        for (int i = 0; i < registerCount; i++) {
            System.out.print(registers[i].size() + " ");
            for (int j = 0; j < registers[i].size(); j++) {
                System.out.print(registers[i].get(j) + " ");
            }
            System.out.println();
        }
    }
}
