/*
  Tibor Pelegrin;
  Pr�ca s poliami
  3.A
*/

import java.util.Scanner;

public class Array{
  private static int cisla[];
  
  //definicia metody pre nacitanie hodnot do pola
  public static void nacitanie(int cisla[]){
    Scanner sc = new Scanner(System.in); 
    
    for(int i = 0; i < cisla.length; i++){
      System.out.print("Zadaj " + (i + 1) + ". hodnotu do pola: ");
      cisla[i] = sc.nextInt();
    } 
  }
  
  //definicia metody pre vypis pola
  public static void vypis(int cisla[]){
    
    for(int i = 0; i < cisla.length; i++){
      System.out.print(cisla[i] + ", ");
    }
  }
  
  //definicia metody pre vypis pola odzadu
  public static void vypisR(int cisla[]){
    
    for(int i = cisla.length - 1; i >= 0; i--){
      System.out.print(cisla[i] + ", ");
    }
  }
  
  //definicia metody pre vypis menu
  public static void menu(){
    System.out.println("\nZadaj m/M pre maximum");
    System.out.println("Zadaj n/n pre minimum");
    System.out.println("Zadaj s/S pre sucet");
    System.out.println("Zadaj v/V pre vypis");
    System.out.println("Zadaj a/A pre vypis pola od najmensiaho");
    System.out.println("Zadaj z/Z pre vypis pola od najvacsieho");
  }
  
  //definicia metody pre opakovanie
  public static String opakovanie(){
    String volba;
    Scanner sc = new Scanner(System.in);
    
    do{
      System.out.println("\nChces opakovat? [Y, y / N, n]");
      volba = sc.nextLine();
      
      if(!volba.equals("Y") && !volba.equals("y") && !volba.equals("N") && !volba.equals("n")){
        System.out.println("Zla volba!");
      }

    }while(!volba.equals("Y") && !volba.equals("y") && !volba.equals("N") && !volba.equals("n"));
    
    return volba;
  }
  
  //definicia metody pre zistenie min
  public static int min(int cisla[]){
    int min = cisla[0];
    
    //for each loop
    for(int cislo : cisla){
      if(min > cislo) min = cislo;
    }

    return min;
  }
  
  //definicia metody pre zistenie max
  public static int max(int cisla[]){
    int max = cisla[0];
    
    //for each loop
    for(int cislo : cisla){
      if(max < cislo) max = cislo;
    }
    
    return max;
  }
  
  //definicia metody pre sucet 
  public static int sum(int cisla[]){
    int sum = 0;
    
    //for each loop
    for(int cislo : cisla){
      sum += cislo;
    }
    
    return sum;
  }
  
  //definicia metody pre bubble sort
  public static int[] bubbleSort(int cisla[]){
    int buffer;
    boolean id; 
    
    do {
      id = false;
      for(int i = 0, j = 1; i < cisla.length - 1; i++, j++){
        if(cisla[i] > cisla[j]){
          buffer = cisla[i];
          cisla[i] = cisla[j];
          cisla[j] = buffer;
          id = true;
        }
      }
    } while (id);
    
    return cisla;
  }
  
  //definicia metody pre vyber moznosti
  public static void vyber(int cisla[]){
    Scanner sc = new Scanner(System.in);
    String volba;
    boolean id = false;
    
    do{
      System.out.print("Tvoja volba: ");
      volba = sc.nextLine();
      
      switch (volba) {
        case "m" : 
        case "M" : 
          System.out.println("\nMax. hodnota v poli je: " + max(cisla));
          id = false;
          break;
        case "n" :
        case "N" : 
          System.out.println("Min. hodnota v poli je: " + min(cisla));
          id = false;
          break;
        case "s" : 
        case "S" : 
          System.out.println("Sucet hodnot v poli je: " + sum(cisla));
          id = false;
          break;
        case "v" : 
        case "V" : 
          System.out.print("Vypis pola: ");
          vypis(cisla);
          id = false;
          break;
        case "a" : 
        case "A" :
          int pole[] = cisla.clone();
          System.out.print("Vypis pola od najmensieho cisla: ");  
          vypis(bubbleSort(pole));   
          id = false;
          break;
        case "Z" : 
        case "z" : 
          int poleR[] = cisla.clone();
          System.out.print("Vypis pola od najvacsieho cisla: ");
          vypisR(bubbleSort(poleR));
          id = false;
          break; 
        default: 
          System.out.println("Zla volba!");
          id = true;
      }  
    }while(id);
  }
  
  //definicia metody pre main
  public static void main(String arg[]){
    int cisla[] = new int[5];
    String volba;
    
    nacitanie(cisla);
                                 
    do{
      menu();
      vyber(cisla);
    
      volba = opakovanie(); 
    }while(volba.equals("y") || volba.equals("Y"));
     
    System.out.println("### Dovidenia! ###");
  }
}

