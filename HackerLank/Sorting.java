import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        
        int swapCount = 0;
        // Write Your Code Here
        for (int i = 0; i < n; i++) {
            // Track number of elements swapped during a single array traversal
            int numberOfSwaps = 0;
            
            for (int j = 0; j < n - 1; j++) {
                // Swap adjacent elements if they are in decreasing order
                if (a[j] > a[j + 1]) {
                    swap(a, j, j + 1);
                    numberOfSwaps++;
                    swapCount++;
                }
            }
            
            // If no elements were swapped during a traversal, array is sorted
            if (numberOfSwaps == 0) {
                break;
            }
        }
        
        System.out.println("Array is sorted in " + swapCount + " swaps.");
        System.out.println("First Element: " + a[0]);
        System.out.println("Last Element: " + a[a.length - 1]);
    }
    
    public static void swap(int[] a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}