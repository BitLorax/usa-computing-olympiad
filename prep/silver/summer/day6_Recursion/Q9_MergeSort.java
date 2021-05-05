package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;

public class Q9_MergeSort {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] nums = new int[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        mergeSort(nums, 0, nums.length);

    }
    private static int[] mergeSort(int[] nums, int lo, int hi) { //hi exclusive
        if (hi - lo > 1) {
            int split = (hi + lo + 1) / 2;
            mergeSort(nums, lo, split);
            mergeSort(nums,split, hi);

            int[] merged = merge(getSubarray(nums, lo, split), getSubarray(nums, split, hi));
            int index = 0;
            for (int i = lo; i < hi; i++) {
                nums[i] = merged[index];
                index++;
            }
            printArray(nums);
            System.out.println();
            return nums;
        } else {
            return nums;
        }
    }
    private static int[] getSubarray(int[] in, int start, int end) {//end exclusive
        int[] result = new int[end - start];
        int index = 0;
        for (int i = start; i < end; i++) {
            result[index] = in[i];
            index++;
        }
        return result;
    }
    private static int[] merge(int[] in1, int[] in2) {
        int[] result = new int[in1.length + in2.length];
        int i = 0;
        int j = 0;
        int index = 0;
        while (i < in1.length && j < in2.length) {
            if (in1[i] < in2[j]) {
                result[index] = in1[i];
                i++;
            } else {
                result[index] = in2[j];
                j++;
            }
            index++;
        }
        while (i < in1.length) {
            result[index] = in1[i];
            i++;
            index++;
        }
        while (j < in2.length) {
            result[index] = in2[j];
            j++;
            index++;
        }
        return result;
    }
    private static void printArray(int[] nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }
}
