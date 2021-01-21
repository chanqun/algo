import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException{
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        for(int i=0; i<N; i++){
            String temp = br.readLine();
            int length = temp.length();
            
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            
            for(int j=0; j<length; j++){
                if(j % 2 == 0){
                    sb1.append(temp.charAt(j));
                }else{
                    sb2.append(temp.charAt(j));
                }
            }
            
            System.out.println(sb1.toString()+" "+sb2.toString());
        }
    }
}