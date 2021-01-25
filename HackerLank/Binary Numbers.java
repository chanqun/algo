import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        
        String binaryNumber = Integer.toBinaryString(n);
        
        int answer = 0;
        int tempCount = 0;
        
        for(int i=0; i<binaryNumber.length(); i++){
            char tempNum = binaryNumber.charAt(i);
            
            if(tempNum == '1'){
                tempCount++;
                answer = Math.max(tempCount, answer);
            }else{
                tempCount = 0;
            }
        }
        
        System.out.println(answer);

        scanner.close();
    }
}
