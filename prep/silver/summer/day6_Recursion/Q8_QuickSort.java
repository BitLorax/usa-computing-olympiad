package day6_Recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//impossible to complete

public class Q8_QuickSort {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] nums = new int[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int[] result = sort(nums, 0, nums.length);
        nums = getSubarray(result, 0, nums.length);
        int pivot = result[result.length - 1];

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
    private static int[] sort(int[] nums, int lo, int hi) {
        int pivot = hi - 1;
        int pivotVal = nums[pivot];
        boolean loFound = false;
        boolean hiFound = false;
        hi = pivot - 1;
        while (lo < hi) {
            int i = nums[lo];
            int j = nums[hi];
            if (i >= pivotVal) {
                loFound = true;
            } else {
                lo++;
            }
            if (j <= pivotVal) {
                hiFound = true;
            } else {
                hi--;
            }
            if (loFound && hiFound) {
                nums[lo] = j;
                nums[hi] = i;
                loFound = false;
                hiFound = false;
                lo++;
                hi--;
            }
        }
        nums[pivot] = nums[lo];
        nums[lo] = pivotVal;
        int[] result = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            result[i] = nums[i];
        }
        result[result.length - 1] = lo;
        return result;
    }
}
