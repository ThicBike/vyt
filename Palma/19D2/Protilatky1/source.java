import java.util.Scanner;
import java.util.ArrayList;

class source{
   //private static ArrayList pole;
  
  public static void main(String arg[]){
    Scanner sc = new Scanner(System.in);
    
    
     
    int n = sc.nextInt();
    int t = sc.nextInt();
    
    int pole[] = new int[n];
    int nad[] = new int[n];
    
    for (int i = 0;i < n; i++ ) {
      
      pole[i] = sc.nextInt(); 
      if(pole[i] > t) nad = push(nad, pole[i]); 
    } 
    
    System.out.println(nad[0]);
   
  }
}

