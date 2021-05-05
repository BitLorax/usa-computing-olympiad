package day4_GreedyMethods;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Q5_Gifts {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int giftCount = Integer.parseInt(st.nextToken());
        int budget = Integer.parseInt(st.nextToken());
        Gift[] gifts = new Gift[giftCount];
        for (int i = 0; i < giftCount; i++) {
            st = new StringTokenizer(in.readLine());
            gifts[i] = new Gift(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(gifts);
        int bought = 0;
        for (Gift gift : gifts) {
            if (gift.getTotal() > budget) {
                if (gift.totalAfterCoupon() > budget) {
                    break;
                } else {
                    bought++;
                    break;
                }
            }
            budget -= gift.getTotal();
            bought++;
        }

        System.out.println(bought);
    }
    static class Gift implements Comparable<Gift> {
        int price;
        int shipping;
        Gift(int price, int shipping) {
            this.price = price;
            this.shipping = shipping;
        }
        int getTotal() {
            return price + shipping;
        }
        int totalAfterCoupon() {
            return price / 2 + shipping;
        }
        public int compareTo(Gift a) {
            if (this.getTotal() != a.getTotal()) {
                return this.getTotal() - a.getTotal();
            }
            return this.totalAfterCoupon() - a.totalAfterCoupon();
        }
    }
}
