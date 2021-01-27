import java.util.*;

class Person {
   protected String firstName;
   protected String lastName;
   protected int idNumber;
   
   // Constructor
   Person(String firstName, String lastName, int identification){
      this.firstName = firstName;
      this.lastName = lastName;
      this.idNumber = identification;
   }
   
   // Print person data
   public void printPerson(){
       System.out.println(
            "Name: " + lastName + ", " + firstName 
         +    "\nID: " + idNumber); 
   }
    
}

class Student extends Person{
   private int[] testScores;

    /*   
    *   Class Constructor
    *   
    *   @param firstName - A string denoting the Person's first name.
    *   @param lastName - A string denoting the Person's last name.
    *   @param id - An integer denoting the Person's ID number.
    *   @param scores - An array of integers denoting the Person's test scores.
    */
    // Write your constructor here
    public Student(String firstName, String lastName, int id, int[] testScores){
        super(firstName, lastName, id);
        this.testScores = testScores;
    }

    /*   
    *   Method Name: calculate
    *   @return A character denoting the grade.
    */
    // Write your method here
    public char calculate() {
        int grade = 0;

        for(int i : testScores){
            grade += i;
        }

        if(testScores.length!=0){
            grade/=testScores.length;
        }
        
        char resultChar = 'T';
        
        if(grade>=90 && grade<=100){
            resultChar = 'O';
        }else if(grade>=80 && grade<=100){
            resultChar = 'E';
        }else if(grade>=70 && grade<=100){            
            resultChar = 'A';            
        }else if(grade>=55 && grade<=100){
            resultChar = 'P';
        }else if(grade>=40 && grade<55){
            resultChar = 'D';
        }
        
        return resultChar;
    }
}

class Solution {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      String firstName = scan.next();
      String lastName = scan.next();
      int id = scan.nextInt();
      int numScores = scan.nextInt();
      int[] testScores = new int[numScores];
      for(int i = 0; i < numScores; i++){
         testScores[i] = scan.nextInt();
      }
      scan.close();
      
      Student s = new Student(firstName, lastName, id, testScores);
      s.printPerson();
      System.out.println("Grade: " + s.calculate() );
   }
}