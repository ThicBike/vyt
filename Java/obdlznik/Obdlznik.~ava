/*
  Obdlznik
  Tibor Pelegrin;
  3.A
*/

import java.io.InputStream;
import java.util.Scanner;
import java.lang.Math;

public class Obdlznik{
  //datove polozky dostupne len z tejto triedy
  private double stranaA;   //namiesto dat. typu float som vyuzil double kvoli vyuzitiu metod pow a sqrt
  private double stranaB;
  private String farba;
  
  //explicitny konstruktor s jednym parametrom, je urceny pre pripad 
  //ze pouzivatel zada stvorec
  public Obdlznik(double stranaA) {
    this(stranaA, stranaA); //volanie kontruktora z konstruktora
  }
  
  //explicitny konstruktor s dvoma parametrami, inicializuje datove polozky
  public Obdlznik(double stranaA, double stranaB){
    //datovym poloznakm priradi hodnoty z parametrov (lokalnych premennych)
    //this nam odkazuje na objekt Obdlznik
    this.stranaA = stranaA;
    this.stranaB = stranaB;
    
    Scanner sc = new Scanner(System.in);
    System.out.print("Zadaj farbu: ");
    farba = sc.nextLine();
  }
  
  //strana A
  //getter sluzi na ziskanie hodnoty datovej polozky
  public double getStranaA(){
    return Math.round(stranaA * 100) / 100.0; //z dovodu zaokruhlenia na 2 desatinne miesta som 
                                              //hodnotu vynasobil 100, zaokruhlil a nasledne vydelil 100
  } 
  //setter sluzi na nastavenie hodnoty datovej polozky
  public void setStranaA(double stranaA){
    this.stranaA = stranaA;
  }
  
  //strana B
  public double getStranaB(){
    return Math.round(stranaB * 100) / 100.0;
  }
  public void setStranaB(double stranaB){
    this.stranaB = stranaB;
  }
  
  //farba
  public String getFarba(){
    return farba;
  }
  public void setFarba(String farba){
    this.farba = farba;
  }
  
  //definicia metody na vypocet obvodu
  public double obvod(){
    return Math.round((2 * stranaA + 2 * stranaB) * 100) / 100.0;
  }
  
  //definicia metody na vypocet obsahu
  public double obsah(){
    return Math.round(stranaA * stranaB * 100) / 100.0;
  }
  
  //definicia metody na vypocet uhlopriecky
  public double uhlopriecka(){
    return Math.round(Math.sqrt(Math.pow(stranaA, 2) + Math.pow(stranaB, 2)) * 100) / 100.00;
  }
  
  //definicia metody na vypis infa
  public void info(String typ){
    if(this.getStranaA() == this.getStranaB()){
      System.out.println("Tvoj obdlznik je typu stvorec!");   //upozorni pouzivatela ze ma stvorec
    }
    
    System.out.println("\nInfo " + typ + ": ");
    System.out.println("Strana A: " + this.getStranaA() + "\nStrana B: " + this.getStranaB());
    System.out.println("Farba: " + this.getFarba());
    System.out.println("Obvod: " + this.obvod() + "\nObsah: " + this.obsah() + "\nUhlopriecka je: " + this.uhlopriecka() + "\n");
  }
  
  public static void main(String arg[]){
    //lokalne premenne
    double stranaA;
    double stranaB;
    
    Scanner sc = new Scanner(System.in);
    System.out.print("Zadaj stranu A v obdlzniku: ");
    stranaA = sc.nextFloat();
    System.out.print("Zadaj stranu B v obdlzniku: ");
    stranaB = sc.nextFloat();
    
    //zistujem ci je dany obdlznik stvorec 
    if(stranaA == stranaB){
      Obdlznik stvorec = new Obdlznik(stranaA); //vytvorili sme objekt stvorec
      stvorec.info("stvorec");   //volanie metody info na objekt stvorec
    }else{
      Obdlznik obdlznik = new Obdlznik(stranaA, stranaB);  //vytvorili sme objekt obdlznik
      obdlznik.info("obdlznik");  //volanie metody info na objekt obdlznik
    }
  }
}



  




