import java.util.Scanner;

public class Kruh{
  //datove polozky
  private static final float PI = 3.14F;
  private float polomer;
  
  //konstruktory
  public Kruh(){
    Scanner sc = new Scanner(System.in);
    do {
      System.out.print("Zadaj polomer kruhu: ");
      polomer = sc.nextFloat();
      if (polomer <= 0) System.out.println("Zadaj kladne cislo!");
    }while(polomer <= 0);
  }
  
  public Kruh(float polomer){
    this.polomer = polomer;
  }
  
  //getters setters
  public void setPolomer(float polomer){
    this.polomer = polomer;
  }
  
  public float getPolomer(){
    return polomer;
  }
  
  //metody
  public float obsah(){
    return PI * (float)Math.pow(polomer, 2);
  }
  
  public float obvod(){
    return 2 * PI * polomer;
  }
  
  public float priemer(){
    return polomer * 2;
  }
  
  //info
  public void info(){
    System.out.println("\nKruh: ");
    System.out.println("Priemer kruhu: " + getPolomer());
    System.out.println("Obsah kruhu: " + obsah());
    System.out.println("Obvod kruhu: " + obvod());
    System.out.println("Priemer kruhu: " + priemer());
  }
  
  //main
  public static void main(String arg[]){
    Kruh kruh1 = new Kruh();
    kruh1.info();
    
    Kruh kruh2 = new Kruh(2);
    kruh2.info();
  }
}

