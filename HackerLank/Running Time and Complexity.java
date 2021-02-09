import java.io.*;
import java.util.*;

public class Solution{

    public static void main(String[] args) throws Exception{
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(br.readLine());
        
        for(int i = 0 ; i < T ; i++){
            int n = Integer.parseInt(br.readLine());
            if(isPrime(n)){
                System.out.println("Prime");
            }else{
                System.out.println("Not prime");
            }
        }
    }
    
    public static boolean isPrime(int n){
        if(n==1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}