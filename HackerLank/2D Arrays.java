import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);
    
    static int[] dy = {0, 0, 0, 1, 2, 2, 2};
    static int[] dx = {0, 1, 2, 1, 0, 1, 2};

    public static void main(String[] args) {
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }
        
        int answer = Integer.MIN_VALUE;
        
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                int temp = 0;
                for(int k = 0; k < 7; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    
                    if(ny<0 || nx<0 || ny>=6 || nx>=6){
                        break;
                    }
                    
                    temp += arr[ny][nx];
                    if(k==6){
                        answer = Math.max(answer, temp);
                    }
                }
            }
        }

        System.out.println(answer);
        
        scanner.close();
    }
}