/*
Obdlznik
Tibor Pelegrin 
3.A
*/

import java.util.Scanner;

public class Obdlznik{
  //datove polozky
  private float stranaA;
  private float stranaB;
  
  //konstruktory
  public Obdlznik(){
    Scanner sc = new Scanner(System.in);
    
    do {
      System.out.print("Zadaj stranu A: ");
      stranaA = sc.nextFloat();
      if (stranaA <= 0) System.out.println("Zadaj kladne cislo!");
    }while(stranaA <= 0);
    
    do {
      System.out.print("Zadaj stranu B: ");
      stranaB = sc.nextFloat();
      if (stranaB <= 0) System.out.println("Zadaj kladne cislo!");
    }while(stranaB <= 0);
  }
  
  public Obdlznik(float stranaA, float stranaB){
    this.stranaA = stranaA;
    this.stranaB = stranaB;
  }
  
  public Obdlznik(float stranaA){
    this(stranaA, stranaA);
  }
  
  //getters setters
  public void setStranaA(float stranaA){
    this.stranaA = stranaA;
  }
  
  public float getStranaA(){
    return stranaA;
  }
  
  public void setStranaB(float stranaB){
    this.stranaB = stranaB;
  }
  
  public float getStranaB(){
    return stranaB;
  }
  
  //metody
  public float obvod(){
    return 2 * (stranaA + stranaB);
  }
  
  public float obsah(){
    return stranaA * stranaB;
  }
  
  public float uhlopriecka(){
    return (float)Math.sqrt(Math.pow(stranaA, 2) + Math.pow(stranaB, 2));
  }
  
  //info
  public void info(){
    System.out.println("\nObdlznik: ");
    System.out.println("StranaA: " + getStranaA());
    
    if(stranaA != stranaB){
      System.out.println("StranaB: " + getStranaB());
    }else{
      System.out.println("Tvoj obdlznik je typu stvorec!");
    }

    System.out.println("Obsah obdlznika: " + obsah());
    System.out.println("Obvod obdlznika: " + obvod());
    System.out.println("Uhlopriecka obdlznika: " + uhlopriecka());
  }
  
  //main
  public static void main(String arg[]){
    Obdlznik obdlznik1 = new Obdlznik();
    obdlznik1.info();
    
    Obdlznik obdlznik2 = new Obdlznik(4.7F, 8.9F);
    obdlznik2.info();
    
    Obdlznik obdlznik3 = new Obdlznik(4.6F);
    obdlznik3.info();
  }
}

