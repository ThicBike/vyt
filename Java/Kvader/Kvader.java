/*
Kvader
Tibor Pelegrin 
3.A

vyuzil som vkladanie kedze na vkladanie sa pytame "ma ?"
a teda ma kvader obdlznik ? ano ma a preto som pouzil 
vkladanie namiesto dedenia
*/

import java.util.Scanner;
import java.lang.Math;

public class Kvader{
  //datove polozky
  private Obdlznik podstava;
  private float vyska;
  
  //konstruktor
  public Kvader(){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("\n### Kvader ###");
    podstava = new Obdlznik();
    do {
      System.out.print("Zadaj stranu C: ");
      vyska = sc.nextFloat();
      if (vyska <= 0) System.out.println("Zadaj kladne cislo!");
    }while(vyska <= 0);
  }
  
  //setters getters
  public Obdlznik getPodstava(){
    return podstava;
  }
  
  public void setPodstava(float stranaA, float stranaB){
    podstava.setStranaA(stranaA);
    podstava.setStranaB(stranaB);
  }
  
  public float getVyska(){
    return vyska;
  }
  
  public void setVyska(float vyska){
    this.vyska = vyska;
  }
  
  //metody
  
  //definicia metody pre vypocet objemu
  public float objem(){
    return podstava.obsah() * vyska;
  }
  
  //definicia metody pre vypocet povrch
  public float povrch(){
    return 2 * podstava.obsah() + 2 * podstava.getStranaA() * vyska + 2 * podstava.getStranaB() * vyska;
  }
  
  //definicia metody pre vypocet uhlopriecky
  public double uhlopriecka(float odvesna1, float odvesna2){
    return Math.sqrt(Math.pow(odvesna1, 2) + Math.pow(odvesna2, 2));
  }
  
  //definicia metody pre vypocet telesovej uhlopriecky
  public double telesovaUhlopriecka(){
    return uhlopriecka((float)uhlopriecka(podstava.getStranaA(), podstava.getStranaB()), vyska);
  }
  
  //definicia metody pre vypocet objemu
  public static String opakovanie(){
    Scanner sc = new Scanner(System.in);
    String volba;
    
    do{
      System.out.println("\nChces opakovat? ano/nie");
      volba = sc.nextLine();
      if(!volba.equals("nie") && !volba.equals("ano")) System.out.println("Zla volba!");
    }while(!volba.equals("nie") && !volba.equals("ano"));
    
    return volba;
  }
  
  //info
  public void info(){
    System.out.println("\nINFO: ");
    System.out.println("Strana A: " + podstava.getStranaA());
    System.out.println("Strana B: " + podstava.getStranaB());
    System.out.println("Strana C: " + getVyska());
    System.out.println("Objem: " + objem());
    System.out.println("Povrch: " + povrch());
    System.out.println("Telesova uhlopriecka: " + String.format("%.2f", telesovaUhlopriecka()));
  }
  
  //main
  public static void main(String arg[]){
    String volba;
    
    do{
      
      Kvader kvader = new Kvader();
      kvader.info();
      volba = opakovanie();
    }while(!volba.equals("nie"));
    
    System.out.println("### Dovidenia! ###");
  }
}

